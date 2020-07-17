/*
*   1. What was the key concept?
*   2. What mistake did I make? (if any)
*   3. Thing to remember from now on.
*/

#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Date{
    int d, m, y, c;
};

// no. of days in month.
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(Date a, Date b){
    // check if the dates are consecutive.
    if ((a.y % 4 == 0 and a.y % 100 != 0) or (a.y % 400 == 0)){
        // leap year. Feb has extra day.
        days[1] = 29;   
    } else {
        days[1] = 28;
    }

    int carry = 0;

    if (a.d + 1 > days[a.m - 1]){
        a.d = 1;
        carry = 1;
    } else {
        a.d ++;
    }

    if (carry == 1){
        if (a.m + 1 > 12){
            a.m = 1;
        } else {
            a.m ++;
            carry = 0;
        }
    }

    if (carry == 1){
        a.y ++;
        carry = 0;
    }

    // cout << a.d << " " << a.m << " " << a.y << endl;

    return (a.d == b.d and a.m == b.m and a.y == b.y);

}

int main(){
    // code here.
    ll n;

    while(cin >> n and n > 0){

        Date cur, last = {-1, -1, -1, -1};
        int ans = 0, cnt = 0;

        for(int i=0; i<n; i++){
            cin >> cur.d >> cur.m >> cur.y >> cur.c;
            if (i > 0 and check(last, cur)){
                ans += (cur.c - last.c);
                cnt++;
            }
            last = cur;
        }

        cout << cnt << " " << ans << endl;
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.