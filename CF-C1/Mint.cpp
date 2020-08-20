#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b, int c, int d) {
  int g = 0;
  g = __gcd(g, a);
  g = __gcd(g, b);
  g = __gcd(g, c);
  g = __gcd(g, d);

  return (a * b * c * d) / g;
}

int main() {

  while (true) {
    int n, t;
    cin >> n >> t;

    if (n == 0 and t == 0) return 0;

    vector<int> coins(n), tables(t);
    for (int &c : coins) cin >> c;
    for (int &tb : tables) cin >> tb;

    for (int i = 0; i < t; i++) {
      int ans_lb = INT_MIN;
      int ans_ub = INT_MAX;

      for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          for (int l = k + 1; l < n; l++) {
            for (int m = l + 1; m < n; m++) {
              int lm = lcm(coins[j], coins[k], coins[l], coins[m]);
              int lb = (tables[i] / lm) * lm;
              int ub = tables[i];

              if (lb < tables[i]) {
                ub = lb + lm;
              }

              ans_lb = max(lb, ans_lb);
              ans_ub = min(ub, ans_ub);
            }
          }
        }
      }

      cout << ans_lb << " " << ans_ub << endl;
    }
  }

  return 0;
}