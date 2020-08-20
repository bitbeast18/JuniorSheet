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
const int N = 1000;

bool valid(int i, int j){
    return (i > 0 and j > 0 and i <= N and j <= N);
}

int main(){
    // code here.
    int n;
    cin >> n;

    ll ans = 0;

    set<pair<int, int>> store;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        store.insert({a, b});
    }

    // traverse diagonals.

    // 1..N rows
    for(int i=1; i<=N; i++){
        ll cur = 0;
        int r = i, c = 1;
        while(valid(r, c)){
            if (store.count({r, c})) cur++;
            r--; c++;
        }

        ans += (cur * (cur - 1)) / 2;
    }

    // cout << ans << endl;

    // 2..N cols
    for(int j=2; j<=N; j++){
        ll cur = 0;
        int r = N, c = j;
        while(valid(r, c)){
            if (store.count({r, c})) cur++;
            r--; c++;
        }

        ans += (cur * (cur - 1)) / 2;
    }

    // cout << ans << endl;

    // diagonals opposite.
    // 1..N rows
    for(int i=1; i<=N; i++){
        ll cur = 0;
        int r = i, c = N;
        while(valid(r, c)){
            if (store.count({r, c})) cur++;
            r--; c--;
        }

        ans += (cur * (cur - 1)) / 2;
    }

    // cout << ans << endl;
    
    // 2..N cols.
    for(int j=1; j<N; j++){
        ll cur = 0;
        int r = N, c = j;
        while(valid(r, c)){
            if (store.count({r, c})) cur++;
            r--; c--;
        }

        ans += (cur * (cur - 1)) / 2;
    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.