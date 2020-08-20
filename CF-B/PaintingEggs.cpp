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
    int n;
    cin >> n;

    vector<char> ans;
    int ma = 0, mb = 0;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        // If I add a then what will be the case.
        int newa = ma + a;
        int newb = mb + b;

        if (abs(newa - mb) > abs(newb - ma)){
            ans.push_back('G');
            mb += b;
        } else {
            ans.push_back('A');
            ma += a;
        }
    }

    if (abs(ma - mb) <= 500 ){
        for(auto a: ans) cout << a;
    } else cout << -1 << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.