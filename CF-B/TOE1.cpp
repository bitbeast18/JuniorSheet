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
#include <set>
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

set<pair<string, pair<string, string>>> dp;

bool done(vector<string> &table, char c){

    if (table[0][0] == c and table[1][1] == c and table[2][2] == c) return true;
    if (table[0][2] == c and table[1][1] == c and table[2][0] == c) return true;

    for(int i=0; i<3; i++){
        if (table[i][0] == c and table[i][1] == c and table[i][2] == c) return true;
        if (table[0][i] == c and table[1][i] == c and table[2][i] == c) return true;
    }

    return false;
}

void wins(int turn, vector<string> target){

    dp.insert({target[0], {target[1], target[2]}});

    if (done(target, 'X') or done(target, 'O')) return;

    if (turn == 0){

        for(int p=0; p<3; p++){
            for(int q=0; q<3; q++){
                if (target[p][q] == '.'){
                    target[p][q] = 'X';
                    wins(1 - turn, target);
                    target[p][q] = '.';
                }
            }
        }


    } else {

        for(int p=0; p<3; p++){
            for(int q=0; q<3; q++){
                if (target[p][q] == '.'){
                    target[p][q] = 'O';
                    wins(1 - turn, target);
                    target[p][q] = '.';
                }
            }
        }

    } 
}

int main(){
    // code here.
    int t; cin >> t;
    NITRO;

    vector<string> table(3, "...");

    wins(0, table);

    while(t--){
        vector<string> target(3);
        for(auto &s: target) cin >> s;

        if (dp.count({target[0], {target[1], target[2]}})) puts("yes");
        else puts("no");
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.
// It's always better to do brute force however simple the solution may be.
// pre-simulation if there are test case. think about offline vs online in terms of complexity.