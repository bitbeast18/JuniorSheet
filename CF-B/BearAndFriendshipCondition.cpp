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
const int N = 2 * 1e5;

vector<vector<int>> adl(N);

void dfs(int node, vector<bool>& vis, vector<int>& comp){
    vis[node] = true;
    comp.push_back(node);

    for(auto v: adl[node]){
        if (!vis[v]){
            dfs(v, vis, comp);
        }
    }
}

int main(){
    // code here.
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adl[a].push_back(b);
        adl[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vector<int> comp;
            dfs(i, vis, comp);

            for(auto v: comp) {
                if(adl[v].size() != comp.size() - 1){
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    puts("YES");

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.