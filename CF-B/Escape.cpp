/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#define endl '\n'
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.
    ld vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    if (vp >= vd){
        puts("0");
        return 0;
    }

    ld dp = t * vp; // distance of princess.
    ld dd = 0; // distance of dragon.
    int ans = 0;
    while(true){

        ld nextMeetPoint = (ld)(vd * (dp - dd)) / (ld)(vd - vp);
        if (nextMeetPoint >= c) break;
        if (nextMeetPoint < c){
            ans++; dp = nextMeetPoint; dd = 0;
            ld extratime = f + (nextMeetPoint / vd);
            dp += (extratime * vp);
        }

        if (dp >= c) break;
    }

    cout << ans << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.