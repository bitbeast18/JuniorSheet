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
const int N = 1e6 + 5;

struct Edge{
    int to, from;
    ld dist;

    bool operator<(Edge& e){
        return dist < e.dist;
    }
};

int par[501];

int root(int u){
    return par[u] < 0 ? u : par[u] = root(par[u]);
}

void unite(int u, int v){

    if ((u = root(u)) == (v = root(v))) return;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

int main(){
    // code here.
    int t;
    cin >> t;

    while(t--){
        int s, p;
        cin >> s >> p;

        memset(par, -1, sizeof par);

        vector<pair<int, int>> cords(p);
        for(auto &c: cords) cin >> c.first >> c.second;

        vector<Edge> edges;

        for(int i=0; i<p; i++){
            for (int j=i+1; j<p; j++){
                ld dist = (cords[i].first - cords[j].first) * (cords[i].first - cords[j].first);
                dist += (cords[i].second - cords[j].second) * (cords[i].second - cords[j].second);
                dist = sqrt(dist);
                edges.push_back({i, j, dist});
            }
        }

        sort(begin(edges), end(edges));

        int k = p - s;
        ld ans = -INF
        for(auto e: edges){
            
            if (root(e.to) != root(e.from)){
                unite(e.to, e.from);
                ans = max(ans, e.dist);
                k--;
            }

            if (k <= 0) break;
        }

        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.