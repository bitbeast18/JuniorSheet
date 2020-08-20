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
    string s;
    cin >> s;
    
    for(auto i: s){
        if (i == '0') cout << i;
        if (i == '2') break;
    }

    for(auto i: s) {
        if (i == '1') cout << i;
    }

    int st = find(begin(s), end(s), '2') - begin(s);

    
    for(int i=st; i<s.size(); i++){
        if (s[i] == '1') continue;
        cout << s[i];
    }

    cout << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.