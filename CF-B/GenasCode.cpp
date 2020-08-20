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

bool beautiful(string s){

    int cnt = 0;
    for(auto i: s){
        if (i == '1') cnt++;
        if (cnt > 1) return false;
        if (i == '1' or i == '0') continue;
        return false;
    }

    return true;
}

int main(){
    // code here.
    int n;
    cin >> n;

    string target = "1";
    int zeroes = 0;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        if (s == "0"){
            cout << 0 << endl;
            return 0;
        }

        if (!beautiful(s)) {
            target = s;
            continue;
        }

        zeroes += s.size() - 1;
    }

    cout << target;
    for(int i=0; i<zeroes; i++) cout << "0";
    cout << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.