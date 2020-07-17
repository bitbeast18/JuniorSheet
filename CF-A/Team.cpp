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

int main(){
    // code here.
    int n, a, b, c, ans = 0;
    cin >> n;

    while(n--){
        cin >> a >> b >> c;
        if (a + b + c > 1) ans ++;
    }    
    cout << ans << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.