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
#include <map>
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

int main(){
    // code here.
    int n, a;
    cin >> n;

    map<int, vector<int>> cnt;

    for(int i=1; i<=n; i++){
        cin >> a;
        cnt[a].push_back(i);
    }

    vector<pair<int, int>> ans;

    for(auto p: cnt){
        if (p.second.size() > 1){
            int d = p.second[1] - p.second[0];
            bool flag = false;
            for(int i=1; i<p.second.size(); i++){
                if (p.second[i] - p.second[i - 1] != d) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) continue;
            ans.push_back({p.first, d});

        } else ans.push_back({p.first, 0});
    }

    cout << ans.size() << endl;
    for(auto a: ans) cout << a.first << " " << a.second << endl;
    
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.