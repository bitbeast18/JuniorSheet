/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(int c){
    int m, n;
    cin >> m >> n;

    vector<string> mat(m);
    for(auto &s: mat) cin >> s;

    int i = m - 1;
    int j = -1;

    for (int i=0; i<n; i++){
        if (mat[m - 1][i] == '@'){
            j = i;
            break;
        }
    }

    string t = "IEHOVA#";
    int s = 0;

    vector<string> ans;

    for (int st=0; st<7; st++){
        // forth
        if (i - 1 >= 0 && t[st] == mat[i - 1][j]) i--, cout << "forth" << ((i == 6) ? "" : " ");
        // right
        if (j + 1 < n and t[st] == mat[i][j + 1]) j++, cout << "right" << ((i == 6) ? "" : " ");
        // left
        if (j - 1 >= 0 and t[st] == mat[i][j - 1]) j--, cout << "left" << ((i == 6) ? "" : " ");
    }

    cout << endl;
 
}

int main(){
    // code here.
    int t;
    cin >> t;

    while(t--) solve(t);

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.