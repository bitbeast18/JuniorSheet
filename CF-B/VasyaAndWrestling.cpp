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
    ll n;
    cin >> n;

    vector<ll> first, second;
    ll sf = 0, ss = 0, a, last;

    for(int i=0; i<n; i++){
        cin >> a;

        if (a < 0) second.push_back(-a), last = 1, ss += -a;
        else first.push_back(a), last = 0, sf += a;
    }

    if (sf > ss){
        cout << "first" << endl;
        return 0;
    }

    if (ss > sf){
        cout << "second" << endl;
        return 0;
    }

    if (ss == sf){
        for(int i=0; i<min(first.size(), second.size()); i++){
            if (first[i] > second[i]){
                cout << "first" << endl;
                return 0;
            }

            if (second[i] > first[i]){
                cout << "second" << endl;
                return 0;
            }
        }

        if (first.size() < second.size()){
            cout << "second" << endl;
            return 0;
        }

        if (second.size() < first.size()){
            cout << "first" << endl;
            return 0;
        }
    }

    if (last == 0){
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.