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
#include <map>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

map<pair<ll, ll>, ll> dp;

ll solve(int i, ll last, vector<pair<ll, ll>>& values){

    if (i >= values.size()){
        return 0;
    }

    if (last >= values[i].first){
        return -INF;    
    }

    if (dp.count({i, last})) return dp[{i, last}];

    ll ans = 0;

    // dont cut.
    ans = max(ans, solve(i + 1, values[i].first, values));
    
    // cut left.
    if (values[i].first - values[i].second > last){
        ans = max(ans, 1 + solve(i + 1, values[i].first, values));
    }
    // cut right.
    ans = max(ans, 1 + solve(i + 1, values[i].first + values[i].second, values));

    return dp[{i, last}] = ans;
}

int main(){
    // code here.

    int n;
    cin >> n;

    vector<pair<ll, ll>> values(n);
    for(auto &v: values) cin >> v.first >> v.second;

    cout << solve(0, -INF, values) << endl;

    // for(auto x: dp) cout << x.first.first << " " << x.first.second << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.