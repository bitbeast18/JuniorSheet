/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

ll lcm (ll a, ll b){
    return ((a * b) / __gcd(a, b));
}

int s[5];

ll eval (int idx, int cnt, ll ub, ll l){

    if (idx == 5) {
        // careful here. we are counting the values that are complement.
        // so reverse this case. or instead you get answer for 
        // number which are divisible with a, a + d...so on.
        return (cnt % 2 == 0) ? (ub / l) : (- ub / l);
    }

    ll ans = 0;

    // consider the cur val.
    ans += eval(idx + 1, cnt + 1, ub, lcm(l, s[idx]));
    // do not consider the cur val.
    ans += eval(idx + 1, cnt, ub, l);

    return ans;
}

void solve(){

    ll n, m, a, d;
    cin >> n >> m >> a >> d;

    s[0] = a;
    s[1] = a + d;
    s[2] = a + 2 * d;
    s[3] = a + 3 * d;
    s[4] = a + 4 * d;

    cout << eval(0, 0, m, 1) - eval(0, 0, n - 1, 1) << endl;
}

int main(){
    // code here.
    int t;
    cin >> t;

    while(t--) solve();
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.