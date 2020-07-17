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
const int N = 1e5 + 5;

int id[N], par[N], w, a;
vector<vector<int>> adl(N);

void dfs(int node, vector<bool>& vis){

    vis[node] = true;

    for(auto n: adl[node]){
        if (!vis[n]){
            dfs(n, vis);
            par[n] = node;
        }
    }
}

int main(){
    // code here.
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=k; i++){
        cin >> w;
        while(w--){
            cin >> a;
            adl[i].push_back(a);
            id[a]++;
        }
    }

    int root = -1;
    for(int i=1; i<=n; i++){
        if (id[i] == 0) {
            if (root != -1) adl[root].push_back(i);
            if (root == -1) root = i;
        }
    }

    vector<bool> vis(n, false);
    
    dfs(root, vis);
    
    for(int i=1; i<=n; i++){
        if (i == root) cout << "0\n";
        else if (par[i] == 0) cout << root << "\n";
        else cout << par[i] << "\n";
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.