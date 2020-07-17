/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

// dont rush. 
// first read the question very carefully.
// if there is a explanation given below then must read it.

#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool check(ll v, ll n, ll k){

    ll cur = k, lines = v;

    while ((v / cur) > 0){
        lines += (v / cur);
        cur *= k;
    } 

    return (lines >= n);
}

int main(){
    // code here.
    ll n, k;
    cin >> n >> k;

    ll left = 1, right = 1e12; 
    ll ans;
    while(left <= right){

        ll mid = left + ((right - left) / 2);

        if (check(mid, n, k)){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.