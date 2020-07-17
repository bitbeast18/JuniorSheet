/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <map>
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
    int n, a;
    cin >> n;

    map<int, int> values;
    for(int i=1; i<=n; i++){
        cin >> a;
        values[a] = i;
    }

    ll m;
    cin >> m;

    ll vasya = 0, petya = 0;
    while(m--){
        cin >> a;
        vasya += values[a];
        petya += n - values[a] + 1;
    }

    cout << vasya << " " << petya << endl;
    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.