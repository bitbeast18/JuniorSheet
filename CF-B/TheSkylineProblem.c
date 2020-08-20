#include<stdio.h>

char c[100][100];

void flood(int x, int y){
    if(c[x][y] == 'X' || c[x][y] == '#')
        return ;
    c[x][y] = '#';
    flood(x+1, y);
    flood(x-1, y);
    flood(x, y+1);
    flood(x, y-1);
}
int main()
{
    int t, i, j;
    scanf("%d", &t);
    while(t--){
        int n = 0;
        while(gets(c[n])){
            if(c[n][0] == '_')
                break;
            n++;
        }
        for(i=0; i<n; i++){
            for(j=0; c[i][j]; j++)
                if(c[i][j] == '*')
                    flood(i, j);
        }
        for(i=0; i<=n; i++)
            puts(c[i]);

    }
}