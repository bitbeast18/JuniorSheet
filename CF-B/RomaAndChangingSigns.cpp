/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    int n, k;
    cin >> n >> k;

    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;

        if (a >= 0) pos.push_back(a);
        else neg.push_back(a);
    }

    sort(begin(neg), end(neg), greater<int>());

    while(k > 0 and !neg.empty()){
        pos.push_back(-neg.back());
        neg.pop_back();
        k --;
    }

    sort(begin(pos), end(pos));

    while(k > 0) {
        pos[0] *= -1;
        k--;
    }

    cout << accumulate(begin(pos), end(pos), 0) + accumulate(begin(neg), end(neg), 0) << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.