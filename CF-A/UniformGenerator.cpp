/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

// learnt about iomanip and setw. Good question.

#include <iostream>
#include <iomanip>
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
    int step, mod, ini = 0;
    while(cin >> step >> mod){
        
        map<int, int> already;
        bool flag = true;

        for(int i=0; i<mod; i++){
            int gen = (ini + step) % mod;
            
            if (already.count(gen) > 0){
                flag = false;
                break;
            } else {
                ini = gen;
                already[gen]++;
            }
        }

        if (flag) cout << setw(10) << step << setw(10) << mod << "    Good Choice\n\n";
        else cout << setw(10) << step << setw(10) << mod << "    Bad Choice\n\n";

    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.