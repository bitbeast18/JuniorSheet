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
const int N = 55;

int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool hasCycle(int i, int j, int li, int lj, int k, char c, vector<vector<char>>& values){

    if (i >= n or j >= m or i < 0 or j < 0) return false;

    if (values[i][j] == '*'){
        return (k >= 4);
    }

    if (values[i][j] != c) return false;

//    cout << i << " " << j << " " << values[i][j] << endl;

    values[i][j] = '*';

    for(int x=0; x<4; x++){
        if (i + dx[x] == li and j + dy[x] == lj) continue;
        if (hasCycle(i + dx[x], j + dy[x], i, j, k+1, c, values)) return true;
    }
    values[i][j] = c;
    return false;
}

int main(){
    // code here.
    cin >> n >> m;

    vector<vector<char>> values(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> values[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (hasCycle(i, j, -1, -1, 1, values[i][j], values)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.