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

ll n;
vector<ll> values;

void generate(ll i){

    if (i >= n) return;

    values.push_back(i);
    generate(i * 10 + 4);
    generate(i * 10 + 7);
}

int main(){
    // code here.
    cin >>  n;

    generate(0);

    cout << lower_bound(begin(values), end(values), n) - begin(values) << endl;


    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.