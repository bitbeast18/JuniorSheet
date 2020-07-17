/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

// wrong interpretation of the question caused two wrong answers.

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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int left = a, right = c, ans, chance = 0;

    while(true){

        ans = left;

        if (right <= left){
            cout << ans << endl;
            return 0;
        }

        if (chance & 1) {
            if (right - d <= left){
                cout << left << endl;
                return 0;
            }
            right -= d;
        } else {
            if (left + b >= right){
                cout << right << endl;
                return 0;
            }
            left += b;
        }
        chance ++;
    }


    cout << left << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.