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
const int N = 800;

struct Edge{
    int to, from, weight;
    bool operator<(Edge& a){
        return weight < a.weight;
    }
};

int par[N];

int root(int u){
    return par[u] < 0 ? u : par[u] = root(par[u]);
}

void unite(int u, int v){
    if((u = root(u)) == (v = root(v))) return;
    if(par[v] > par[u]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

int main(){
    // code here.

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        memset(par, -1, sizeof par);

        vector<pair<int, int>> cords(n + 1);
        for(int i=1; i<=n; i++){
            cin >> cords[i].first >> cords[i].second;
        }

        int m, k = 0;
        cin >> m;
        // need theses many more edges.
        // some edges may form a cycle and hence don't contribute to mst.
        // careful.
        while(m--){
            int a, b;
            cin >> a >> b;

            if (root(a) != root(b)) unite(a, b), k--;
        }

        k--;
        k += n;

        // for(int i=1; i<=n; i++) cout << par[i] << " ";
        // cout << endl;

        if (k <= 0){
            cout << "No new highways need" << endl;
            if (t > 0) cout << endl;
            continue;
        }

        vector<Edge> edges;

        // create edges.
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                // create an edge from i to j and push.
                int dist = (cords[i].first - cords[j].first) * (cords[i].first - cords[j].first);
                dist += (cords[i].second - cords[j].second) * (cords[i].second - cords[j].second);

                edges.push_back({i, j, dist}); 
            }
        }

        sort(begin(edges), end(edges));
        
        vector<Edge> ans;

        for(auto e: edges){   

            // cout << e.to << " " << e.from << endl;

            if (root(e.to) != root(e.from)){
                ans.push_back(e);
                unite(e.to, e.from);
                k--;
            }

            if (k <= 0) break;
        }

        for(auto e: ans){
            cout << e.to << " " << e.from << endl;
        }
        if (t > 0) cout << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.