/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <algorithm>
using namespace std;

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
    int n; cin >> n;
    while(n --){

        string a, b;
        cin >> a >> b;

        string ans = "";

        if (a.size() > b.size()) swap(a, b);

        while(a.size() < b.size()) a += '0';    
        
        a += '0';
        b += '0';
        
        int carry = 0;

        for(int i=0; i<(int)(a.size()); i++){
        
            int inter = carry + (a[i] - '0') + (b[i] - '0');
        
            carry = inter / 10;
            ans += ((inter % 10) + '0');
        }

        reverse(begin(ans), end(ans));
        while(ans.back() == '0') ans.pop_back();

        reverse(begin(ans), end(ans));
        while(ans.back() == '0') ans.pop_back();
        
        cout << ans << endl;
    }



    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.