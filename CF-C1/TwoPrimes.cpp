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
const int N = 2 * 1e7;

vector<pair<int, int>> twins;
bitset<N> primes;

void generate(){
    primes.set();
    primes[0] = primes[1] = false;
    
    for(int i=2; i * i < N; i++){
        if (primes[i]){
            for(int j = 2 * i; j < N; j += i) primes[j] = false;
        }
    }

    for(int i=2; i < N; i++){
        if (primes[i] and primes[i - 2]){
            twins.push_back({i - 2, i});
        }
    }
}

int main(){
    // code here.
    generate();
    
    int t;
//    cout << twins.size() << endl;
    while(cin >> t){
        printf("(%d, %d)\n", twins[t-1].first, twins[t-1].second);
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.