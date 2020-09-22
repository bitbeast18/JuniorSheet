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
using namespace std;

#define endl '\n';
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO ios_base::sync_with_stdio(false); cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Point{
    ll score, sem, id;
};

int main(){
    // code here.
    int n;
    cin >> n;

    vector<Point> scores;
    for (int i=0; i<n; i++){
        ll val;
        cin >> val;
        scores.push_back({val, 1, i});
        
        cin >> val;
        scores.push_back({val, 2, i});
    }

    int k = n / 2;

    sort(begin(scores), end(scores), [](Point a, Point b){
        if (a.score == b.score) return a.id < b.id;
        else return a.score < b.score;
    });

    vector<int> sem1(n, 0), sem2(n, 0);

    for (int i=0; i<n; i++){
        auto cur = scores[i];
        
        if (cur.sem == 1) sem1[cur.id] = 1;
        else sem2[cur.id] = 1;
    }

    int idx = 0;

    for (auto s: scores) {
        if (s.sem == 1){
            sem1[s.id] = 1;
            idx++;
        }

        if (idx == k) break;
    }

    idx = 0;

    for (auto s: scores) {
        if (s.sem == 2) {
            sem2[s.id] = 1;
            idx++;
        }

        if (idx == k) break;
    }

    for (int i: sem1) cout << i;
    cout << endl;
    for (int i: sem2) cout << i;
    cout << endl;


    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.