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
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 105;

int dp[N][4];

int solve(int i, int last, vector<int>& values){

    if (i >= values.size()){
        return 0;
    }

    if (dp[i][last] != -1) return dp[i][last];
    
    int ans = INF;

    // contest.
    if (last != 1 and (values[i] & 1)){
        ans = min(ans, solve(i + 1, 1, values));
    }

    // gym.
    if (last != 2 and (values[i] & 2)){
        ans = min(ans, solve(i + 1, 2, values));
    }

    ans = min(ans, 1 + solve(i + 1, 0, values));

    return dp[i][last] = ans;
}

int main(){
    // code here.
    int n;
    cin >> n;

    vector<int> values(n);
    for(auto &v: values) cin >> v;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, values) << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.