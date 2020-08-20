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

struct Exam{
    ll grade, penalty;
    bool operator<(Exam& a){
        if (penalty == a.penalty) return grade < a.grade;
        else return penalty < a.penalty;
    }
};

int main(){
    // code here.
    ll n, r, avg;
    cin >> n >> r >> avg;

    ll agg = 0;

    vector<Exam> exams(n);
    for(auto &e: exams) cin >> e.grade >> e.penalty, agg += e.grade;

    sort(begin(exams), end(exams));

    ll ans = 0;

    for(int i=0; i<n; i++){
        
        if (avg * n <= agg) break;
        
        if ((n * avg - agg) > r - exams[i].grade){
            agg += (r - exams[i].grade);
            ans += ((r - exams[i].grade) * exams[i].penalty);
            
        } else {
            agg += (n * avg - agg);
            ans += ((n * avg - agg) * exams[i].penalty);
        }

    }

    cout << ans << endl;

    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.