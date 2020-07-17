/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

// WRONG SOLUTION...
// AGAIN OVERCOMPLICATED SIMPLE THINGS.
// THERE WAS JUST A FORMULA.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <numeric>
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
    int n;
    cin >> n;

    if (n <= 2){
        puts("YES");
        return 0;
    }

    vector<ll> values(n);
    for(auto &v: values) cin >> v;

    ll agg = accumulate(begin(values), end(values), 0ll);
    ll mean = agg / n;
    mean += (agg % n > n / 2);
    ll last = 0;
    for(auto v: values){
        if (last == 0)
            last = abs(v - mean);
        else {
            if (abs(v - mean) != 0 and abs(v - mean) != last) {
                puts("NO");
                return 0;
            }
        }
    }

    puts("YES");

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.