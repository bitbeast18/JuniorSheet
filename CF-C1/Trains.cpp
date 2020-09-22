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

int main(){
    // code here.
    ll a, b;
    cin >> a >> b;

    ll masha = 0, dasha = 0, dashaT = a, mashaT = b;

    while(true){

        if (dashaT < mashaT) {
            dasha++;
            dashaT += a;
            // cout << "dasha " << dashaT << endl;
        }
        else if (dashaT > mashaT) {
            masha++;
            mashaT += b;
            // cout << "masha " << mashaT << endl;
        }
        else {
            if (a > b) dasha++;
            else if (b > a) masha++;

            break;
        }
    }

    if (masha > dasha) puts("Masha");
    else if (dasha > masha) puts("Dasha");
    else puts("Equal");

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.