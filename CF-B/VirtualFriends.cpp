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
const int N = 1e5 + 5;

int par[N];

int root (int u){
    return (par[u] < 0) ? u : par[u] = root(par[u]); 
}

void unite(int u, int v){
    if ((u = root(u)) == (v = root(v))) return;
    if (par[v] < par[u]) swap(u, v);

    par[u] += par[v];
    par[v] = u;
}

int id = 0;

map<string, int> labels;

int label(string s){
    if (labels.count(s) <= 0) labels[s] = id++;
    return labels[s];
}

int main(){
    // code here.
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        labels.clear();
        id = 0;
        memset(par, -1, sizeof par);

        while(n--){
            string a, b;
            cin >> a >> b;

            int la = label(a);
            int lb = label(b);

            unite(la, lb);
            cout << -par[root(la)] << endl;
        }
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.