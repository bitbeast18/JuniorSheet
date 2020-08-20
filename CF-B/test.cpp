#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    string s = "harshal";

    rotate(begin(s), end(s) - 1, end(s));
    cout << s << endl;


    return 0;
}