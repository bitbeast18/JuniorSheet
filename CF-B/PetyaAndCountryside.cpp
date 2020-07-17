/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
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
    int n, ans = 0;
    cin >> n;

    vector<int> values(n);
    for(auto &v: values) cin >> v;

    for (int i=0; i<n; i++){

        int left = i - 1, right = i + 1;

        while(left >= 0 and values[left] <= values[left + 1]) left--;
        while(right < n and values[right] <= values[right - 1]) right++;

        ans = max(ans, (i - left - 1) + (right - i - 1) + 1);
    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.