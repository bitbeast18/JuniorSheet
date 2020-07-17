/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(12)
#define PI (ld)acos((ld)-1)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.
    PRECISE;
    ld d, h, v, e;
    cin >> d >> h >> v >> e;

    ld is = (PI * d * d * e) / 4;

    if (v < is or (fabs(is - v) < 1e-6)){
        puts("NO");
    } else {
        puts("YES");
        cout << ((PI * d * d * h) / (4 * (v - is))) << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.