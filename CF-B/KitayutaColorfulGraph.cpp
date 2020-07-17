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
const int N = 101;

vector<vector<vector<int>>> adl(N, vector<vector<int>>(N));

bool hasPath(int node, int dest, int color, vector<bool>& vis){
    
    if (node == dest) return true;

    vis[node] = true;

    for(auto v: adl[node][color]){
        if (!vis[v]){
            bool ans = hasPath(v, dest, color, vis);
            if (ans) return true;
        }
    }

    return false;
}

int main(){
    // code here.

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adl[a][c].push_back(b);
        adl[b][c].push_back(a);
    } 

    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;

        vector<bool> vis(n + 1, false);

        int cnt = 0;
        for(int i=1; i<=m; i++){
            if (hasPath(a, b, i, vis)) cnt++;
            vis.assign(n + 1, false);
        }

        cout << cnt << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.