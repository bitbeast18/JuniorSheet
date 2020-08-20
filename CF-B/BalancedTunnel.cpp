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
#include <map>
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
    int n, time = 1, a;
    cin >> n;

    map<int, int> watch;

    vector<int> values(n);
    for(auto &i: values) cin >> i;

    for(int i=0; i<n; i++){
        cin >> a;
        watch[a] = time++;
    }

    int mx = -1, cnt = 0;
    
    for(int i=0; i<n; i++){
        mx = max(mx, watch[values[i]]);
        if (mx > watch[values[i]]) cnt++;
    }

    cout << cnt << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.