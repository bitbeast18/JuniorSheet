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
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Point {
    int a, b;
    bool operator<(Point &x){
        if (x.a == a) return b < x.b;
        else return a < x.a;
    }

    bool operator==(Point &x){
        return (x.a == a and x.b == b);
    }
};

int main(){
    // code here.
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<Point> values(k);
    for(auto &v: values) cin >> v.a >> v.b;

    sort(begin(values), end(values));

    while(t--){

        Point c;
        cin >> c.a >> c.b;

        int cnt = 0, flag = 0;
        for (int i=0; i<k; i++){
            
            if (c == values[i]){
                puts("Waste");
                flag = 1;
                break;
            } else if (values[i] < c){
                cnt ++ ;
            } else break;
        }

        if (flag) continue;

        int val = ((c.a - 1) * m) + c.b - cnt;

        if (val % 3 == 0) puts("Grapes");
        else if (val % 3 == 1) puts("Carrots");
        else puts("Kiwis");
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.