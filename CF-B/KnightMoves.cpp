/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int dirX[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dirY[] = {1, -1, 1, -1, 2, 2, -2, -2};

bool valid (string nex){
    return (nex[0] >= 'a' and nex[0] <= 'h' and nex[1] >= '1' and nex[1] <= '8');
}

int ans(string s, string t){

    queue<pair<string, int>> up;
    set<string> vis;

    up.push({s, 0});
    vis.insert(s);

    while(!up.empty()){

        auto cur = up.front();
        up.pop();

        // process
        if (cur.first == t){
            return cur.second;
        }

        vis.insert(cur.first);

        for(int i=0; i<8; i++){
            string nex;

            nex.push_back(cur.first[0] + dirX[i]);
            nex.push_back(cur.first[1] + dirY[i]);
            
            if (!vis.count(nex) and valid(nex)){
                up.push({nex, cur.second + 1});
            }
        }
        
    }

    return -1;
}

int main(){
    // code here.
    string s, t;
    while(cin >> s >> t){
        cout << "To get from " << s << " to " << t << " takes " << ans(s, t) << " knight moves." << endl; 
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.