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
#define PRECISE cout << fixed << setprecision(12)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

string orig, in;
int origVal;

bool match(string s){
    int aa = 0;
    for(int i=0; i<s.length(); i++){
        if (s[i] == '+') aa++;
        else aa--;
    }

    return aa == origVal;
}

int solve(int idx, string s){

    if (idx >= s.length()){
        return match(s);
    }

    int ans = 0;

    if (s[idx] == '?'){
        s[idx] = '+';
        ans += solve(idx + 1, s);
        s[idx] = '-';
        ans += solve(idx + 1, s);
    } else {
        ans = solve(idx + 1, s);
    }

    return ans;
}

int main(){
    // code here.
    cin >> orig >> in;
    origVal = 0;
    for(auto s: orig){
        if (s == '+') origVal++;
        else origVal--;
    }

    int ans = solve(0, in);
    
    int cnt = 1; 
    for(auto c: in) 
        if (c == '?') cnt *= 2;

    PRECISE;
    cout << (ld)ans / (ld)cnt << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.