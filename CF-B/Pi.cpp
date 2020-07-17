/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(6)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    // code here.
    PRECISE;
    int n;

    while(cin >> n){

        if (n == 0) return 0;

        vector<int> values(n);
        for(auto &v: values) cin >> v;

        int cnt = 0, valid = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int a = values[i], b = values[j];
                if (__gcd(a, b) == 1) valid++;
                cnt++;
            }
        }

        if (valid == 0){
            cout << "No estimate for this data set.\n";
            continue;
        }

        cout << (ld)sqrt((ld)(6 * cnt) / (ld)(valid)) << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.