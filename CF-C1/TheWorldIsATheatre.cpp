/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cstring>
using namespace std;

#define endl '\n';
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 100;

vector<vector<ll>> table(N, vector<ll>(N, 0));

ll nCr(ll n, ll r){
    return table[n][r];
}

int main(){
    // code here.

    for (int i=0; i<N; i++) table[i][0] = 1;

    for(int i=1; i<N; i++){
        for (int j=1; j<N; j++){
            table[i][j] = table[i-1][j] + table[i-1][j-1];
        }
    }


    ll n, m, t;
    cin >> n >> m >> t;

    ll ans = 0;

    for(int i=4; i<t; i++){
        ll inter = nCr(n, i);
        if (t - i >= 1) inter *= nCr(m, t - i);

        ans += inter; 
    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.