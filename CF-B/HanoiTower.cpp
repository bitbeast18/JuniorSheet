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



void hanoi(int n, int from, int to, int temp, int ta, int tb, int tc, int pa, int pb, int pc){
    
    if (n <= 0) return;
    
    hanoi(n - 1, from, to, temp, ta, tb, tc, pa, pb, pc);
    check(ta, tb, tc, pa, pb, pc);
    hanoi(n - 1, temp, to, from, ta, tb, tc, pa, pb, pc);
}

int main(){
    // code here.
    int n;
    cin >> n;

    int pa = 0, pb = 0, pc = 0;
    
    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        if (v == 1) pa |= (1 << i);
        if (v == 2) pb |= (1 << i);
        if (v == 3) pc |= (1 << i);
    }

    hanoi(((1 << n) - 1), 0, 0, pa, pb, pc);
    if (ans) 

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.