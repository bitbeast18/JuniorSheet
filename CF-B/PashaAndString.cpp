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
    
    int n = s.length();

    vector<int> cnt(n, 0);
    int m;
    cin >> m;

    while(m--){
        int a; 
        cin >> a;

        a--;

        cnt[a]++; 
        if (a > 0) cnt[n - a]--;
    }

    for(int i=1; i<n; i++){
        cnt[i] += cnt[i - 1];
    }

    for(int i=0; i<n; i++){
        if (cnt[i] & 1){
            swap(s[i], s[n - i - 1]);
            cnt[n - i - 1]--;
        }
    }

    cout << s << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.