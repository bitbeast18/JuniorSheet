/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <string>
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

    string s;
    cin >> s;

    int cnt = 0;

    while(s.size() > 1){
        int ans = 0;
        for(auto i: s) ans += i - '0';
        s = to_string(ans);
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.