/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <math.h>
#include <iomanip>
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
    PRECISE;

    int n, k;
    cin >> n >> k;

    ld la, lb;
    cin >> la >> lb;
    ld dist = 0;
    ld a, b;
    for(int i=0; i<n - 1; i++){
        cin >> a >> b;

        dist += sqrt((la - a) * (la - a) + (lb - b) * (lb - b));
        la = a;
        lb = b;
    }

    dist *= k;
    cout << dist / 50 << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.