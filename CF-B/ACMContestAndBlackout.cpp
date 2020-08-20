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
#include <cstring>
#include <cmath>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Edge{
    int to, from, weight;
    bool operator<(Edge& e) const{
        return weight < e.weight;
    }
    bool operator==(Edge& e) const{
        return (to == e.to and from == e.from and weight == e.weight);
    }
};

int par[110];

int root(int u){
    return (par[u] < 0) ? u : par[u] = root(par[u]);
}

void unite(int u, int v){
    if ((u = root(u)) == (v = root(v))) return;
    if (par[v] < par[u]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

int main(){
    // code here.
    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        memset(par, -1, sizeof par);

        vector<Edge> edges(m);
        for(auto &e: edges){
            cin >> e.to >> e.from >> e.weight;
        }

        sort(begin(edges), end(edges));
        vector<Edge> mst;
        int cnt = 0, ans1 = 0, ans2 = INF;

        for(auto e: edges){
            if (root(e.to) != root(e.from)){
                unite(e.to, e.from);
                cnt++; ans1 += e.weight;
                mst.push_back(e);
            }

            if (cnt == n-1) break;
        }

        for(auto d: mst){
            cnt = 0;
            int tans = 0;
            memset(par, -1, sizeof par);
            for(auto e: edges){
                if (e == d) continue;

                if (root(e.to) != root(e.from)){
                    unite(e.to, e.from);
                    cnt++; tans += e.weight;
                }

                if (cnt == n-1) break;
            }
            // there may be some critical edges removing which
            // the graph should never be connected.
            // hence must check cnt == n-1.
            if (cnt == n-1) {
                ans2 = min(ans2, tans);
            }
        }

        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.