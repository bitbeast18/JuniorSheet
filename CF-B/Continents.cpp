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

int m, n;
char land;

void markAll(int i, int j, char c, int& cnt, vector<string>& mp){

    if (i == m) return;
    if (i == -1) return;
    
    if (j == n) j = 0;
    if (j == -1) j = n - 1;

    if (mp[i][j] == land) {
        cnt++;
        mp[i][j] = c;
    } else return;

    markAll(i + 1, j, c, cnt, mp);
    markAll(i - 1, j, c, cnt, mp);
    markAll(i, j + 1, c, cnt, mp);
    markAll(i, j - 1, c, cnt, mp);
}

int main(){
    // code here.
    while(cin >> m >> n){

        vector<string> mp(m);
        for(auto &s: mp) cin >> s;

        int x, y;
        cin >> x >> y;

        land = mp[x][y];

        int waste = 0;
        markAll(x, y, '0', waste, mp);

        char r = '1';

        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (mp[i][j] == land){
                    int cnt = 0;
                    markAll(i, j, r, cnt, mp);
                    ans = max(ans, cnt);
                    r++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.