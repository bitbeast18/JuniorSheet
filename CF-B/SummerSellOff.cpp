/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.
    int n, f;
    cin >> n >> f;

    vector<pair<ll, ll>> values(n);
    for(auto &v: values) cin >> v.first >> v.second;

    // missed a case if there is a case where a.first if already greater then we should not touch it.
    // and let other cases come forward which can be improved. So subtracting the previous values gives
    // the increase and we should consider that instead of the raw value.
    sort(begin(values), end(values), [&](pair<ll, ll> a, pair<ll, ll> b){
        return min(2 * a.first, a.second) - min(a.first, a.second) > min(2 * b.first, b.second) - min(b.first, b.second);
    });

    for(int i=0; i<f; i++){
        values[i].first *= 2;
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += min(values[i].first, values[i].second);
    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.