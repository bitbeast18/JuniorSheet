/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <algorithm>
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
    int n;
    cin >> n;

    vector<int> values(n);
    for(auto &v: values) cin >> v;

    int q, h;
    cin >> q;

    while(q--){
        
        cin >> h;

        int lb = lower_bound(begin(values), end(values), h) - begin(values);
        int ub = upper_bound(begin(values), end(values), h) - begin(values);

        if (lb == 0){
            cout << "X";
        } else {
            cout << values[lb - 1];
        }

        if (ub == n) {
            cout << " X";
        } else {
            cout << " " << values[ub];
        }

        cout << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.