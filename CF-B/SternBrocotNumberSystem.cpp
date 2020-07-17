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

void figure(pair<int, int> l, pair<int, int> r, pair<int, int> target){

    auto mid = make_pair(l.first + r.first, l.second + r.second);
    
    // cout << mid.first << " " << mid.second << endl;

    if (mid.first == target.first and mid.second == target.second) return;
    
    else if (mid.first * target.second > mid.second * target.first){
        cout << 'L';
        figure(l, mid, target);
    }
    
    else{
        cout << 'R';
        figure(mid, r, target);
    }

}

int main(){
    // code here.
    int a, b;

    while(cin >> a >> b){

        if (a == 1 and b == 1) return 0;

        figure({0, 1}, {1, 0}, {a, b});
        cout << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.