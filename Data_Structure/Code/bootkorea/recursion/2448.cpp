#include<cstdio>
 
char DB[][6]=
{ "  *  ",
  " * * ",
  "*****" };
char MAP[3500][6500];
 
void solve(int n, int y, int x)
{
    if (n == 1)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                MAP[y + i][x + j] = DB[i][j];
        return;
    }
    solve(n / 2, y, x + 3 * n / 2);
    solve(n / 2, y + 3 * n / 2, x);
    solve(n / 2, y + 3 * n / 2, x + 3 * n);
}
 
int main()
{
    int n;
    scanf("%d", &n);
    solve(n / 3, 0, 0);
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<2*n-1;j++)
            printf("%c", MAP[i][j] == '*' ? '*' : ' ');
    return 0;
}
