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
    int n, k;
    cin >> n >> k;

    vector<vector<char>> mp(n, vector<char>(n, 'S'));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if ((i + j) % 2 == 0 and k > 0) mp[i][j] = 'L', k--;
        }
    }

    if (k){
        puts("NO");
    } else {
        puts("YES");
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++) cout << mp[x][y];
            cout << endl;
        }
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.