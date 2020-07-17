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
const int N = 55;

vector<vector<int>> adl(N);

void dfs(int node, vector<bool>& vis, int& cnt){
    
    vis[node] = true; cnt++;
    
    for(auto v: adl[node]) {
        if (!vis[v]){
            dfs(v, vis, cnt);
        }
    }
}

int main(){
    // code here.
    int n, m; cin >> n >> m;

    vector<int> deg(n + 1, 0);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        deg[a]++; deg[b]++;

        adl[a].push_back(b);
        adl[b].push_back(a);
    }

    vector<pair<int, int>> values;

    for(int i=1; i<=n; i++){
        values.push_back(make_pair(i, deg[i]));
    }

    sort(begin(values), end(values), [](pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    });

    ll ans = 1;
    vector<bool> vis(n + 1, false);

    for(auto v: values){
        if (!vis[v.first]){
            int cnt = -1;
            dfs(v.first, vis, cnt);
            ans *= (1ll << cnt);
        }
    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.