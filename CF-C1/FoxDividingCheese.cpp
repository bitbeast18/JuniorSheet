/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cstring>
using namespace std;

#define endl '\n';
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.

    ll a, b;
    cin >> a >> b;

    ll ans = 0;

    ll n = max(a, b);

    for(int i=2; i * i <= n; i++){

        while((a % i == 0) or (b % i == 0)){
            
            if (a == b) {
                cout << ans << endl;
                return 0;
            }
            
            if (a % i == 0) a /= i, ans++;
            
            if (a == b) {
                cout << ans << endl;
                return 0;
            }
            
            
            if (b % i == 0) b /= i, ans++;

            if (a == b) {
                cout << ans << endl;
                return 0;
            }

        }
    }

    cout << -1 << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.