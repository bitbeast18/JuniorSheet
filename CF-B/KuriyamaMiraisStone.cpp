/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
    int n;
    cin >> n;

    vector<ll> sorted(n + 1, 0), values(n + 1, 0);
    for(int i=1; i<=n; i++){
        cin >> values[i];
        sorted[i] = values[i];
    }

    sort(begin(sorted), end(sorted));

    for(int i=2; i<=n; i++){
        values[i] += values[i - 1];
        sorted[i] += sorted[i - 1];
    }

    int m;
    cin >> m;

    while(m--){
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1){
            cout << values[r] - values[l - 1] << endl;
        } else {
            cout << sorted[r] - sorted[l - 1] << endl;
        }
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.