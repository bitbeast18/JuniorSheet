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

    vector<vector<bool>> adm(n, vector<bool>(n, false));
    vector<int> deg(n, 0);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        a--; b--;
        deg[a]++; deg[b]++;
        adm[a][b] = true;
        adm[b][a] = true;
    }

    int ans = 0;

    while(true){
        int cnt = 0;
        vector<int> target;

        for(int i=0; i<n; i++){

            if (deg[i] == 1){
                cnt++;
                for(int ad=0; ad<n; ad++){
                    if (adm[i][ad]){
                        target.push_back(ad);
                        adm[i][ad] = false;
                        adm[ad][i] = false;
                    }
                }
                deg[i]--;
            }
        }

        if (cnt == 0) break;
        ans++;
        for(auto x: target){
            deg[x]--;
        }
    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.