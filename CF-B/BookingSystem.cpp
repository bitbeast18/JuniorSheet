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

struct table{
    int id, cap, ass = -1;
    bool operator<(table& a){
        return cap < a.cap;
    }
};

struct offer{
    int id, sz, amt;
    bool operator<(offer &a){
        if (amt == a.amt) return sz < a.sz;
        else return amt > a.amt;
    }
};

int main(){
    // code here.
    int n;
    cin >> n;

    vector<offer> offers(n);
    for(int i=0; i<n; i++){
        cin >> offers[i].sz >> offers[i].amt;
        offers[i].id = i + 1;
    }

    int m;
    cin >> m;

    vector<table> tables(m);
    for(int i=0; i<m; i++){
        cin >> tables[i].cap;
        tables[i].id = i + 1;
    }

    sort(begin(tables), end(tables));
    sort(begin(offers), end(offers));

    ll ans = 0, cnt = 0;

    for(int i=0; i<n; i++){
        for(int t=0; t<m; t++){
            if (tables[t].ass == -1 and tables[t].cap >= offers[i].sz){
                tables[t].ass = offers[i].id;
                ans += offers[i].amt; cnt++;
                break;
            }
        }
    }

    cout << cnt << " " << ans << endl;

    for(int i=0; i<m; i++){
        if (tables[i].ass != -1){
            cout << tables[i].ass << " " << tables[i].id << endl;
        }
    }

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.