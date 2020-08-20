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

ll l(ll a, ll b){
    return ((a * b) / __gcd(a, b));
}

ll solve(int idx, int cnt, ll lcm, int n, vector<ll>& values){


    if (idx >= values.size()){
        // decide
        
        if (cnt % 2 == 0){
            return (n / lcm);
        } else {
            return -(n / lcm);
        }
    }

    ll ans = 0;

    ans += solve(idx + 1, cnt + 1, l(lcm, values[idx]), n, values);
    ans += solve(idx + 1, cnt, lcm, n, values);

    return ans;
}

int main(){
    // code here.
    ll n, m;

    while(cin >> n >> m){
        vector<ll> values(m);
        for(auto &i: values) cin >> i;

        cout << solve(0, 0, 1, n, values) << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.