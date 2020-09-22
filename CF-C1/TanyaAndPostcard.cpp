/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cstring>
using namespace std;

#define endl '\n';
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool isLower(int i){
    int lb = (int) 'a';
    int ub = (int) 'z';

    if (i >= lb and i <= ub) return true;
    else return false;
}

int main(){
    // code here.
    
    string s, t;
    cin >> s >> t;

    vector<int> req(256, 0), avail(256, 0);

    for (char c: s) req[c]++;
    for (char c: t) avail[c]++;

    int yays = 0, whoops = 0;

    int lb = (int) 'A';
    int ub = (int) 'z';

    for (int i=lb; i<=ub; i++){
        if (req[i] <= avail[i]) {
            yays += req[i];
            avail[i] -= req[i];
            req[i] = 0;
        } else {
            yays += avail[i];
            req[i] -= avail[i];
            avail[i] = 0;
        }
    }

    for (int i=lb; i<=ub; i++){
        if (req[i] > 0){
            if (isLower(i)){
                if (avail[i - 32] <= 0) continue;
                if (avail[i - 32] >= req[i]){
                    whoops += req[i];
                    avail[i - 32] -= req[i];
                    req[i] = 0;
                } else {
                    whoops += avail[i - 32];
                    req[i] -= avail[i - 32];
                    avail[i - 32] = 0;
                }
            } else {
                if (avail[i + 32] <= 0) continue;

                if (avail[i + 32] >= req[i]){
                    whoops += req[i];
                    avail[i + 32] -= req[i];
                    req[i] = 0;
                } else {
                    whoops += avail[i + 32];
                    req[i] -= avail[i + 32];
                    avail[i + 32] = 0;
                }
            }
        }
    }


    cout << yays << " " << whoops << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.