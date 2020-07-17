/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e2 + 5;

vector<int> ans;
int id[N];
vector<vector<int>> adl(N);

void toposort(int node, vector<bool>& vis){
    vis[node] = true;

    for(auto n: adl[node]){
        if (!vis[n]){
            toposort(n, vis);
        }
    }

    ans.push_back(node);
}

int main(){
    // code here.
    int n, m;
    
    while(cin >> n >> m && n != 0){

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            adl[a].push_back(b);
            id[b]++;
        }

        vector<bool> vis(n + 1, false);

        // toposort and print the result.
        for(int i=1; i<=n; i++){
            if (id[i] == 0 and !vis[i]){
                toposort(i, vis);
            }
        }

        for(auto v: ans) cout << v << " ";
        cout << endl;

        for(int i=1; i<=N; i++){
            adl[i].clear();
        }
        
        memset(id, 0, sizeof id);
        ans.clear();
    }


    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.