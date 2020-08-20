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
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.

    int n;
    cin >> n;

    vector<int> values(n), dp(n);
    for(auto &i: values) cin >> i;

    dp[0] = 0;
    for(int i=1; i<n; i++){
        dp[i] = values[i] - values[i - 1]; 
    }

    int bestln = 0, curln = 0, curval = 0;
    int lastmin = values[0], lastmini = 0;

    for(int i=0; i<n; i++){
        if (abs(curval + dp[i]) < 2){
            curln++;
            curval += dp[i]; 
        } else {
            bestln = max(bestln, curln);
            curln -= lastmini + 1;

            lastmin = values[lastmini + 1];
            lastmini++;
        }

        if (lastmin >= values[i]){
            lastmin = values[i];
            lastmini = i;
        } 
    }

    cout << bestln << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.