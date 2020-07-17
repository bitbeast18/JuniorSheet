/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

// you lose focus after coding for a long time.
// Practice long span of coding 

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
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
    int n, k;
    cin >> n >> k;

    vector<int> values(n + 1, 0);
    for(int i=1; i<=n; i++){
        cin >> values[i];
        values[i] += values[i - 1];
    }

    int ans = -1, wt = INF;
    for(int i=k; i<=n; i++){
        if (wt > (values[i] - values[i - k])) {
            ans = i - k + 1;
            wt = values[i] - values[i - k];
        }
    }
 
    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.