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

struct Op{
    ll l, r, d;
};

int main(){
    // code here.
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> opCount(m, 0), values(n), valCount(n, 0);
    vector<Op> ops(m);

    for (auto &v: values) cin >> v;

    for (auto &v: ops) {
        cin >> v.l >> v.r >> v.d;
        v.l--; v.r--;
    }

    for (int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;

        x--; y--;

        opCount[x]++;
        if (y + 1 < m) opCount[y + 1]--;
    }

    for (int i=0; i<m; i++){
        if (i > 0) opCount[i] += opCount[i - 1];
        ops[i].d *= opCount[i];
    }


    for (int i=0; i<m; i++){
        auto cur = ops[i];
        valCount[cur.l] += cur.d;
        if (cur.r + 1 < n) valCount[cur.r + 1] -= cur.d;
    }

    for (int i=0; i<n; i++){
        if (i > 0) valCount[i] += valCount[i - 1];
        cout << valCount[i] + values[i] << " ";
    }

    cout << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.