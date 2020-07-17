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

int solve(int n, int m, int c){
// Key is count the no. of white cells in range (8, n) x (8, m).

// I was thinking of some inclusion exclusion.

}

int main(){
    // code here.
    ll n, m, c;
    cin >> n >> m >> c;

    while(n > 0 or m > 0 or c > 0){

        cout << solve(n, m, c) << endl;

        cin >> n >> m >> c;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.