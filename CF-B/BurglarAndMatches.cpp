/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int >> values(m);
    for(int i=0; i<m; i++){
        cin >> values[i].first >> values[i].second;
    }

    sort(begin(values), end(values), [&](pair<int, int> a, pair<int, int> b){
        if (a.second == b.second) return a.first > b.first;
        else return a.second > b.second;
    });

    int ans = 0, i = 0;

    while(n > 0 and i < m){
        if (n - values[i].first < 0){
            ans += values[i].second * n;
            n -= n;
        } else {
            ans += values[i].first * values[i].second;
            n -= values[i].first;
        }

        i++;
    }

    cout << ans << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.