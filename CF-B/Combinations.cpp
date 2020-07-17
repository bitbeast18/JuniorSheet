/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
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
    
    // build pascal table.
    vector<vector<ll>> dp(101, vector<ll>(101, 0));
    
    for(int i=0; i<101; i++) dp[i][0] = 1;
    
    for(int n=1; n<101; n++){
        for(int k=1; k<=n; k++){
            dp[n][k] = dp[n - 1][k] + dp[n - 1][k - 1];
        }
    }

    ll a, b;
    while(cin >> a >> b and a != 0){
        cout << a << " things taken " << b << " at a time is " << dp[a][b] << " exactly.\n";
    }



    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.