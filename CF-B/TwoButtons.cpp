/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#define endl '\n'
#define inf 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

// for such problems do bfs and get the result.
// n will be max 2 * 1e4; 
// Finally learnt something new from a div 2 b problem.

ll go(int n, int m){

    if (n >= m) return (n - m);

    queue<pair<int, int>> up;
    up.push({n, 0});

    vector<int> vis(10 * m, 0);

    while(!up.empty()){
        auto cur = up.front();
        up.pop();

        vis[cur.first] = 1;

        if (cur.first == m) {
            return cur.second;
        }

        if (!vis[cur.first * 2] and cur.first < m) up.push({cur.first * 2, cur.second + 1});
        if (!vis[cur.first - 1] and cur.first > 1) up.push({cur.first - 1, cur.second + 1});
    }

    return -1;

}

int main(){
    // code here.
    int n, m;
    cin >> n >> m;
    
    cout << go(n, m) << endl;

    return 0;   
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.