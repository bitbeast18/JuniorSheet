#include <cstdio>

char maze[100][100];

void floodfill(int i, int j){
    // No need to check the valid i, j because there is no way out.
    if (maze[i][j] == 'X' or maze[i][j] == '#') return;

    maze[i][j] = '#';

    floodfill(i + 1, j);
    floodfill(i - 1, j);
    floodfill(i, j + 1);
    floodfill(i, j - 1);
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n = 0;

        while(gets(maze[n])){
            if (maze[n][0] == '_') break;
            n++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; maze[i][j]; j++){
                if (maze[i][j] == '*') {
                    floodfill(i, j); 
                    break;
                }
            }
        }

        for(int i=0; i<=n; i++) puts(maze[i]);       
    }

    return 0;
}