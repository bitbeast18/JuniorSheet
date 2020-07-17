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
#define inf 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.
    int n, xo, yo;
    cin >> n >> xo >> yo;
    
    vector<pair<int, int>> points(n);
    for(auto &p: points) cin >> p.first >> p.second;

    int ans = 0;
    for(int i=0; i<n; i++){
        if (points[i].first != inf){
            ans++;
            for(int p=0; p<n; p++){
                if (p == i) continue;
                if (points[p].first == inf) continue;
                ll l = (points[i].first - xo) * (points[p].second - yo);
                ll r = (points[i].second - yo) * (points[p].first - xo);
                if (l == r){
                    points[p].first = inf;
                    points[p].second = inf;
                } 
            }
            points[i].first = inf;
            points[i].second = inf;
        }
    }

    cout << ans << endl;
    
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.