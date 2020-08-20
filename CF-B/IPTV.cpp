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
#include <map>
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
const int N = 5000;

int par[N];

int root(int u){
    return (par[u] < 0) ? u : par[u] = root(par[u]);
}

void unite(int u, int v){
    if ((u = root(u)) == (v = root(v))) return;
    if (par[u] > par[v]) swap(u, v);

    par[u] += par[v];
    par[v] = u;
}

struct Edge{
    int to, from, cost;
    bool operator<(Edge& e){
        return cost < e.cost;
    }
};

int main(){
    // code here.
    int t; cin >> t;

    while(t--) {

        int n, m;
        cin >> n >> m;

        memset(par, -1, sizeof par);

        map<string, int> id;
        vector<Edge> edges(m);
        int tag = 0;

        for(int i=0; i<m; i++){
            string a, b;
            cin >> a >> b;

            if (id.count(a) == 0) id[a] = tag++;
            if (id.count(b) == 0) id[b] = tag++;

            edges[i].to = id[a];
            edges[i].from = id[b];
            cin >> edges[i].cost;     
        } 

        sort(begin(edges), end(edges));
        int cnt = 0, cost = 0;
        for(auto e: edges){
            
            if (root(e.to) != root(e.from)){
                unite(e.to, e.from);
                cost += e.cost; cnt++;
            }

            if (cnt == n - 1) break;
        }

        cout << cost << endl;
        if (t > 0) cout << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.