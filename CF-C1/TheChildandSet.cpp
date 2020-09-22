#include <bits/stdc++.h>

using namespace std;

int lowbit(int val){
    for (int i=0; i<30; i++){
        if ((val >> i) & 1) return (1 << i);
    }
    return 0;
}

int main(){

    int sum, limit;
    cin >> sum >> limit;

    map<int, vector<int>> pos;

    for (int i=1; i<=limit; i++){
        pos[lowbit(i)].push_back(i);
    }

    vector<int> ans;

    for (int i=30; i>=0; i--){
        while((1 << i) <= sum and !pos[(1 << i)].empty()){
            ans.push_back(pos[(1 << i)].back());
            sum -= (1 << i);
            pos[(1 << i)].pop_back();
        }
    }

    if (sum == 0) {
        cout << ans.size() << endl;
        for (auto i: ans) cout << i << " ";
    } else cout << -1 << endl;

    return 0;
}