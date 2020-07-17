/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

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

ll modpow(ll b, ll p, ll m){

    if (p == 0){
        return 1;
    }

    ll ans = modpow(b, p / 2, m) % m;
    ans = (ans * ans) % m; 

    if (p & 1) {
        return (ans * b) % m; 
    } else return (ans) % m; 

}
int main(){

    // code here.

    ll b, p, m;
    
    while(cin >> b >> p >> m){
        cout << modpow(b, p, m) << endl;
    }


    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.