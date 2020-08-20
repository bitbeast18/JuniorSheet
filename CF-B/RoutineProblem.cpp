#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * d == b * c){
        cout << "0/1" << endl;
        return 0;
    }

    // the numerators are same and difference is 
    // in the denominators. i.e b > d;
    if (a * d < c * b){
    
        b *= c;
        d *= a;
    
        int diff = b - d;
        int g = __gcd(diff, b);
        cout << diff / g << "/" << b / g << endl;
    } else {
    
        a *= d;
        c *= b;

        int diff = a - c;
        int g = __gcd(diff, a);
        cout << diff / g << "/" << a / g << endl;
    }

    return 0;
}

// key learnings.
// 1. how to compare ratios 
