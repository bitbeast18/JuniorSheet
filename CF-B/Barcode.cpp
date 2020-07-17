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
const int N = 1e3 + 5;
    int n, m, x, y;

int dp[N][N][2];

int solve(int i, int l, int color, vector<int> whites){

    if (i >= whites.size()){
        return 0;
    }

    if (dp[i][l][color] != -1){
        return dp[i][l][color];
    }

    int ans = INF;
    
    int val = (color == 1) ? (whites[i]) : (n - whites[i]); 

    if (l < x){
        ans = min(ans, val + solve(i + 1, l + 1, color, whites));

    } else if (l >= x and l < y) {
        ans = min(ans, val + solve(i + 1, l + 1, color, whites));
        ans = min(ans, (n - val) + solve(i + 1, 1, 1 - color, whites));    

    } else {
        ans = min(ans, (n - val) + solve(i + 1, 1, 1 - color, whites));
    }

    return dp[i][l][color] = ans;
}

int main(){
    // code here.
    cin >> n >> m >> x >> y;

    vector<int> whites(m, 0);
    memset (dp, -1, sizeof dp);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        for(int c=0; c<m; c++) whites[c] += (s[c] == '.');
    }

    cout << min(solve(0, 0, 0, whites), solve(0, 0, 1, whites)) << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.