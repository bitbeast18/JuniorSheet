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
#include <bitset>
using namespace std;

#define endl '\n';
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e7;

bitset<N> sieve;
vector<int> primes;

void generate(){

    sieve.set();
    sieve[0] = sieve[1] = false;
    for(int i=2; i * i < N; i++){
        if (sieve[i]){
            primes.push_back(i);
            for(int j = 2*i; j<N; j+=i) sieve[j] = false;
        }
    }
}

int main(){
    // code here.

    generate();

    ll t;
    while(cin >> t){

        string ans;

        if (t % 2 == 0){
            ans = "2 2 ";
            t -= 4;
        } else {
            ans = "2 3 ";
            t -= 5;
        }

        if (t < 4) {
            cout << "Impossible." << endl;
            continue;
        }

        bool flag = true;

        // Now t is even.
        for(auto p: primes){
            if (t < p) break;
            if (sieve[t - p]){
                cout << ans;
                cout << p << " " << t - p << endl;

                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Impossible." << endl;
    }


    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.