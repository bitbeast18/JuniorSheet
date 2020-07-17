/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(10)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.

    PRECISE;

    ll n, l;
    cin >> n >> l;

    vector<ld> values(n);
    for(auto &v: values) cin >> v;

    sort(begin(values), end(values));

    // find the largest gap between the light posts.

    ld gap = values[0];

    for(int i=1; i<n; i++){
        gap = max(gap, (values[i] - values[i - 1]) / 2);
    }

    gap = max(gap, l - values[n - 1]);

    cout << gap << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.