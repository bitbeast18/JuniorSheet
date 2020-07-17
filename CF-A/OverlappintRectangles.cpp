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

struct Rect {
    int xa, xb, ya, yb;
};

int main(){
    // code here.
    int t;
    cin >> t;

    while(t--){

        Rect a, b;
        cin >> a.xa >> a.ya >> a.xb >> a.yb;
        cin >> b.xa >> b.ya >> b.xb >> b.yb;

        if (a.xb > b.xa and a.yb > b.ya and a.xa < b.xb and a.ya < b.yb){

            // bottom left 
            cout << max(a.xa, b.xa) << " ";
            cout << max(a.ya, b.ya) << " ";

            // top right
            cout << min(a.xb, b.xb) << " ";
            cout << min(a.yb, b.yb);

            cout << endl;

        } else {
            cout << "No Overlap\n";
        }

        if (t){
            cout << endl;
        }

    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.