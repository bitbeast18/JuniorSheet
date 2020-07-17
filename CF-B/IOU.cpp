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
    int n, m;
    cin >> n >> m;

    vector<int> each(n, 0);
    for(int i=0; i<m; i++){
        int t, f, a;
        cin >> t >> f >> a;
        t--; f--;

        each[t] -= a;
        each[f] += a;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if (each[i] > 0) ans += each[i];
    }

    cout << ans << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.