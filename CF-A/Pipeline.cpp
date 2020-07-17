/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

// wrong solution.

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

int main(){
    // code here.
    ll n, k;
    cin >> n >> k;
    n--; k--;

    if (n <= k){
        puts("1");
    } else if (n > (k * (k + 1)) / 2) {
        puts("-1");
    } else {

        ll left = 1, right = k;
        
        while(left <= right){

            ll mid = left + ((right - left) / 2);
            ll op = (mid * (mid + 1)) / 2; 

            if (op == n){
                cout << mid << endl;
                return 0; 
            } else if (op < n){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.