/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <algorithm>
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
    int n;
    cin >> n;

    string s;
    cin >> s;

    string ans = "";

    for(int i=0; i<s.size(); i++){
        if (i & 1){
            ans = ans + s[i];
        } else ans = s[i] + ans;
    }

    if (n & 1) 
        reverse(begin(ans), end(ans));

    cout << ans;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.