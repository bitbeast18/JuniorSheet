#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int mod = 2000000011;

ll pow(ll n, ll p) {
  ll ans = 1;

  for (int i = 1; i <= p; i++) {
    ans *= n;
    ans %= mod;
  }

  return ans%mod;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    ll n;
    cin >> n;
    cout << "Case #" << i << ": " << pow(n, n - 2) << endl;
  }

  return 0;
}