/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Rect{
    ld xa, xb, ya, yb;
};

int main(){
    // code here.
    PRECISE;
    char c;
    vector<Rect> rectangles;
    while(cin >> c and c != '*'){

        Rect temp;
        cin >> temp.xa >> temp.ya >> temp.xb >> temp.yb;

        rectangles.push_back(temp);
    }
    int cnt = 1;
    ld a, b;
    while(cin >> a >> b){

        if (fabs(a - 9999.9) < 1e-6 and fabs(b - 9999.9) < 1e-6) return 0;

        bool flag = true;

        for (int p=1; p<=(int)rectangles.size(); p++){
        
            Rect x = rectangles[p-1];
            // cout << a << " " << b << endl;
            // cout << x.xa << " " << x.xb << " " << x.ya << " " << x.yb << endl;
            // cout << (x.xa > a) << endl;
            if ((x.xa < a) and (x.xb > a) and (x.ya > b) and (x.yb < b)){
                cout << "Point " << cnt << " is contained in figure " << p << endl;
                flag = false;
            }
        }

        if (flag) {
            cout << "Point " << cnt << " is not contained in any figure\n";
        }
        cnt++;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.