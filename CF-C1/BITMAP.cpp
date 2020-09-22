#include <bits/stdc++.h>

using namespace std;

void paint(int i, int j, int wi, int wj, vector<vector<int>>& distmap, vector<vector<int>>& bitmap, vector<vector<int>>& vis){

    if (i < 0 or j < 0 or i >= distmap.size() or j >= distmap[0].size()) return;    
    if (vis[i][j] == 1) return;

    vis[i][j] = 1;

    if (bitmap[i][j] == 1) return;

    int curDist = abs(i - wi) + abs(j - wj);

    if (distmap[i][j] < curDist) return;
    else {
        distmap[i][j] = curDist;

        paint(i - 1, j, wi, wj, distmap, bitmap, vis);
        paint(i, j + 1, wi, wj, distmap, bitmap, vis);
        paint(i + 1, j, wi, wj, distmap, bitmap, vis);
        paint(i, j - 1, wi, wj, distmap, bitmap, vis);
    }

}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> bitmap(n, vector<int>(m)), distmap(n, vector<int>(m, INT_MAX));        
        
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                char ch;
                cin >> ch;

                bitmap[i][j] = ch - '0';
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (bitmap[i][j] == 1){
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    
                    distmap[i][j] = 0;
                    
                    paint(i - 1, j, i, j, distmap, bitmap, vis);
                    paint(i, j + 1, i, j, distmap, bitmap, vis);
                    paint(i + 1, j, i, j, distmap, bitmap, vis);
                    paint(i, j - 1, i, j, distmap, bitmap, vis);
                }
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cout << distmap[i][j] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}