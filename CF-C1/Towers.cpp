/*
 *   1. What was the key concept?
 *   2. What mistake did I make? (if any)
 *   3. Thing to remember from now on.
 */

#include <algorithm>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define endl '\n';
#define INF 0x3f3f3f3f;
#define INFL 0x3f3f3f3f3f3f3f3f;
#define NITRO                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(false)
#define PRECISE cout << fixed << setprecision(9)

using ll = long long int;
using ld = long double;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Tower {
  int id, value;
};

int main() {
  // code here.
  int n, k;
  cin >> n >> k;

  deque<Tower> values(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i].value;
    values[i].id = i + 1;
  }

  auto comp = [](Tower a, Tower b) { return a.value < b.value; };

  sort(begin(values), end(values), comp);

  int m = 0;

  vector<pair<int, int>> ans;

  for (int i = 0; i < k; i++) {
    auto f = values.front();
    values.pop_front();
    auto b = values.back();
    values.pop_back();

    if (b.value - f.value > 1) {
      f.value++;
      b.value--;
      m++;
      ans.push_back({b.id, f.id});

      values.push_back(b);
      values.push_back(f);

    } else {
      values.push_back(b);
      values.push_back(f);
      break;
    }

    sort(begin(values), end(values), comp);
  }

  int mx = -INF;
  int mn = INF;

  for (auto v : values) {
    mx = max(v.value, mx);
    mn = min(v.value, mn);
  }

  cout << mx - mn << " " << m << endl;

  for (auto p : ans) cout << p.first << " " << p.second << endl;

  return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.