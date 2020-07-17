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
#include <cstring>
using namespace std;

#define endl '\n'
#define inf 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 16;

ll n, l, r, x;
ll dp[N][(1 << 15) + 100];
ll solve(int idx, int mask, vector<int>& values){

    if (idx >= n) {
        int cnt = __builtin_popcount(mask);
        int totalValue = 0, mn = inf, mx = -inf;

        for(int i=0; i<n; i++){
            if ((mask >> i) & 1){
                totalValue += values[i];
                mn = min(mn, values[i]);
                mx = max(mx, values[i]);
            }        
        }

        int diff = mx - mn;
        return (cnt >= 2 and totalValue <= r and totalValue >= l and diff >= x);
    }

    if (dp[idx][mask] != -1) return dp[idx][mask];

    ll ans = 0;

    // take idx.
    ans += solve(idx + 1, (mask | (1 << idx)), values);

    // don't take idx.
    ans += solve(idx + 1, mask, values);

    return dp[idx][mask] = ans;
}

int main(){
    // code here.
    cin >> n >> l >> r >> x;

    vector<int> values(n);
    for(auto &v: values) cin >> v;

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, values);

    return 0; 
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.