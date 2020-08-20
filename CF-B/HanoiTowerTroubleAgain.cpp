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

bool isSquare(ll n){
    ll sn = sqrt(n);
    return (sn * sn == n);
}

int main(){
    // code here.
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> values(n, 0);
        
        ll cur = 1;
        
        while(true){

            bool init = true;
            for(int i=0; i<n; i++){
                if (values[i] == 0 or isSquare(values[i] + cur)) {
                    values[i] = cur;
                    cur++; init = false;
                    break;
                }
            }
            if (init) break;
            if (cur > 1e6) break;    
        }
        if (cur > 1e6) cout << -1 << endl;
        else cout << cur - 1 << endl;
    }


    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.