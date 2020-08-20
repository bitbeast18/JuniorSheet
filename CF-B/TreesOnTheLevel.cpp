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
#include <queue>
#include <deque>
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

struct Node {
    int data = -1;
    Node *left=nullptr, *right=nullptr;
};

int process(vector<string>& paths, Node* root){

    for(auto s: paths){

        deque<char> in;
        for(auto i: s) in.push_back(i);

        int num = 0;
        string dir = "";

        in.pop_back(); in.pop_front();

        while(in.front() != ',') {
            num *= 10;
            num += in.front() - '0';
            in.pop_front();
        }

        while(in.back() != ','){
            dir.push_back(in.back());
            in.pop_back();
        }

        reverse(begin(dir), end(dir));
        Node* cur = root;
        for(auto d: dir){
            if (d == 'L') {
                if (cur->left == nullptr) {
                    cur->left = new Node();
                }
                cur = cur->left;
            }
            else {
                if (cur->right == nullptr){
                    cur->right = new Node();
                }
                cur = cur->right;
            }
        }

        if (cur->data != -1){
            return 0;
        } else cur->data = num;
    }

    return 1;
}

vector<int> ans;

void printLO(Node* root){

    queue<Node*> up;

    up.push(root);

    while(!up.empty()){
        Node* cur = up.front();
        up.pop();

        if (cur->data == -1) {
            cout << "not complete\n";
            return;
        }

        ans.push_back(cur->data);

        if (cur->left != nullptr) up.push(cur->left);
        if (cur->right != nullptr) up.push(cur->right);
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;
}

int main(){
    // code here.

    string s;
    vector<string> paths;

    while(cin >> s){
        if (s == "()"){


            Node* root = new Node();

            if (process(paths, root)){
                printLO(root);
            } else cout << "not complete" << endl;

            paths.clear();
            ans.clear();

        } else paths.push_back(s);
    }



    return 0;
}

// Check the corner cases. (n = 1).
// Check overflows. (int vs ll).
// Be consistent.