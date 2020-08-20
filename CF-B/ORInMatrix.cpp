#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> values(n, vector<int>(m)), ans(n, vector<int>(m, 1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> values[i][j];
            if (values[i][j] == 0){
                for(int r=0; r<n; r++) ans[r][j] = 0;
                for(int c=0; c<m; c++) ans[i][c] = 0;
                
            }
        }
    }

    vector<vector<int>> newa(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ans[i][j] == 1){
                for(int r=0; r<n; r++) newa[r][j] = 1;
                for(int c=0; c<m; c++) newa[i][c] = 1;
            }
        }
    }

    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(newa[i][j] != values[i][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}