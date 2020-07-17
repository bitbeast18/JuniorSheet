/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// wrong solution.

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Point{
    ld x, y;
    bool operator==(Point &a){
        return (a.x == x and a.y == y);
    }
};

int main(){
    // code here.
    PRECISE;
  
    Point fa, fb, sa, sb;
    while(cin >> fa.x >> fa.y >> fb.x >> fb.y >> sa.x >> sa.y >> sb.x >> sb.y){

        if (fa == sa){

            ld diff = fb.x - fa.x;
            cout << sb.x + diff << " " << sb.y << endl;

        } else if (fa == sb) {

            ld diff = fb.x - fa.x;
            cout << sa.x + diff << " " << sa.y << endl;

        } else if (fb == sa){

            ld diff = fb.x - fa.x;
            cout << sb.x + diff << " " << sb.y << endl;

        } else {

            ld diff = fb.x - fa.x;
            cout << sa.x + diff << " " << sa.y << endl;
        }

    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.