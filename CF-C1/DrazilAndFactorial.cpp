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

    int n;
    cin >> n;

    string a;
    cin >> a;

    string ans;
    for(auto i: a){
        
        int v = i - '0';
        
        if (v == 1 or v == 0) continue;
        if (v == 2 or v == 3 or v == 5 or v == 7) ans.push_back(i);

        if (v == 4) ans.append("223");
        if (v == 6) ans.append("35");
        if (v == 8) ans.append("2227");
        if (v == 9) ans.append("3327");
    }
    
    sort(begin(ans), end(ans), greater<char>());

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.