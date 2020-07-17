/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

// read question carefully.
// make sure what the question is asking.

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
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool match(pair<int, int> a, pair<int, int> b){
    
    if ((a.first > b.second) or (a.second < b.first)) return false;
    else return true;

}

int main(){
    // code here.
    int p, q, l, r;
    cin >> p >> q >> l >> r;

    vector<pair<int, int>> xrange(q), yrange(p);

    for(auto &v: yrange) cin >> v.first >> v.second;
    for(auto &v: xrange) cin >> v.first >> v.second;

    int ans = 0;


    for(int i=l; i<=r; i++){
        bool flag = false;
        for(int x=0; x<q; x++){
    
            auto cur = xrange[x];

            cur.first += i;
            cur.second += i;

            for(int y=0; y<p; y++){
                if (match(cur, yrange[y])) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        ans += flag;
    }

    cout << ans << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.