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
    string s; int k;
    cin >> s >> k;

    for(int i=0; i<s.length(); i++){

        int best = i;
        for(int j=i+1; j<min(i+k+1, (int)s.length()); j++){
            if (s[j] > s[best]) best = j;
        }

        if (best != i){
            rotate(begin(s) + i, begin(s) + best, begin(s) + best + 1);
            k -= (best - i);
        }
    }

    cout << s << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.