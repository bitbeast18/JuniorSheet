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

int main(){
    // code here.
    int n;
    cin >> n;

    deque<int> a, b;
    
    int na, nb;
    cin >> na;
    for(int i=0; i<na; i++) {
        int v;
        cin >> v;

        a.push_back(v);
    }

    cin >> nb;
    for(int i=0; i<nb; i++) {
        int v;
        cin >> v;

        b.push_back(v);
    }

    int cnt = 0;

    while(cnt < 1e6){
        
        if (a.empty()){
            cout << cnt << " " << 2 << endl;
            return 0;
        }

        if (b.empty()){
            cout << cnt << " " << 1 << endl;
            return 0;
        }

        int cura = a.front(); a.pop_front();
        int curb = b.front(); b.pop_front();

        if (cura < curb){
            b.push_back(cura); b.push_back(curb);
        } else {
            a.push_back(curb); a.push_back(cura);
        }

        cnt++;

    }   

    cout << -1 << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.