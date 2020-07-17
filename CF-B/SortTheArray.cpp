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

    vector<ll> values(n);
    for(auto &v: values) cin >> v;

    if (is_sorted(begin(values), end(values))){
        puts("yes");
        puts("1 1");
        return 0;
    }

    int i = 1, len = 1;

    while(i < n){
        if (values[i] < values[i - 1]){
            while(i + len < n and values[i + len] < values[i + len - 1]) len++;
            break;
        } i++;
    }

    reverse(begin(values) + i - 1, begin(values) + i + len);
    
    if(is_sorted(begin(values), end(values))){
        puts("yes");
        cout << i << " " << i + len << endl;
    } else puts("no");

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.