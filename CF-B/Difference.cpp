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
const int N = 1e6 + 5;

void dfs(int node, vector<bool>& vis, vector<vector<int>>& adl, vector<int>& wait, vector<int>& time){

    vis[node] = true;
    
    int wt = 0;
    for(auto v: adl[node]){
        dfs(v, vis, adl, wait, time);
        wt += wait[v] + time[v];
    }
    
    wait[node] = wt;
}

void solve(int v, int e, int cas){
        
    vector<vector<int>> adl(v);
    vector<int> time(v);

    for(auto &t: time) cin >> t;

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;

        a--; b--;

        adl[a].push_back(b);
    }

    vector<int> wait(v, 0);
    vector<bool> vis(v, false);
    
    for(int i=0; i<v; i++){
        if (!vis[i])
            dfs(i, vis, adl, wait, time);
    }

    vector<int> ans(v, 0);

    for(int i=0; i<v; i++){
        for(int c=0; c<v; c++){
            if (c == i) continue;
            if (wait[i] == wait[c]) ans[i] += time[c];
        }
    }

    int q;
    cin >> q;

    printf("Case #%d:\n", cas+1);

    while(q--){
        int n;
        cin >> n; n --;
        
        cout << ans[n] << endl;
    }

    cout << endl;
}

int main(){
    // code here.

    NITRO;
    
    int i=1, v, e;

    while(cin >> v >> e){
        
        if (v == 0 and e == 0) return 0;
        solve(v, e, i);
        i++;
    } 
    
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.