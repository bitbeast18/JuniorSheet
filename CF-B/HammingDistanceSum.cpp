#include <iostream>
#include <vector>

using ll = long long int;
using namespace std;

// good problem.

int main(){

    string a, b;
    cin >> a >> b;

    int sa = a.size(), sb = b.size();

    vector<ll> ones(sb), zeroes(sb);

    if (b[0] == '1') ones[0] = 1;
    else zeroes[0] = 1;

    for(int i=1; i<sb; i++){
        ones[i] = ones[i - 1] + (b[i] == '1');
        zeroes[i] = zeroes[i - 1] + (b[i] == '0');
    }

    ll ans = 0;

    for(int i=0; i<sa; i++){
        if (a[i] == '0') {
            if (i == 0) ans += ones[sb - sa + i];
            else ans += ones[sb - sa + i] - ones[i - 1]; 
        } else {
            if (i == 0) ans += zeroes[sb - sa + i];
            else ans += zeroes[sb - sa + i] - zeroes[i - 1]; 
        }
    }

    cout << ans << endl;

    return 0;
}