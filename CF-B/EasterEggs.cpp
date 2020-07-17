/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool check(string ans, int x, char c){
    
    bool dec = true;

    for (int i=1; i<4; i++){
        dec = (dec and (ans[x + i] != c) and (ans[x - i] != c));
    }

    return dec;
}

int main(){
    // code here.
    int n;
    cin >> n;

    int k = n / 7;
    int rem = n % 7;

    string colors = "ROYGBIV";
    
    for (int i=0; i<k; i++){
        cout << colors;
    }

    string ans = "";
    while(rem--) ans += "*";
    
    ans = (colors + ans + colors);

    for (int i=0; i<(int)ans.size(); i++){
        if (ans[i] == '*'){
            for(auto c: colors){
                if(check(ans, i, c)){
                    ans[i] = c;
                    break;
                }
            }
        }
    }
    
    ans = ans.substr(7, n % 7);
    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.