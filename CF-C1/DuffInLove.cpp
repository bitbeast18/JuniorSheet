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

bool isLucky(ll x){

    for(ll a=2; a * a <= x; a++){
        if ((x % (a * a)) == 0) return false;
    }

    return true;
}

int main(){
    // code here.
    ll n;
    cin >> n;

    ll ans = 0;
    // sqrt(n)
    for(ll i=1; i * i <= n; i++){
        if (n % i == 0){
            if (isLucky(i)) ans = max(ans, i);
            if (isLucky(n / i)) ans = max(ans, n / i);
        }
    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.