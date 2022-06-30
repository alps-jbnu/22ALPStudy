#include <bits/stdc++.h>

// 2448 별 찍기 - 11

using namespace std;

static const int INF = 1000000000;

int N;
char star[3080][6160];

void makingStar(int n, int i, int j)
{
    if(n == 0)
    {
        star[i][j] = '*';
        star[i+1][j+1] = '*';
        star[i+1][j-1] = '*';
        star[i+2][j-2] = '*';
        star[i+2][j-1] = '*';
        star[i+2][j] = '*';
        star[i+2][j+1] = '*';
        star[i+2][j+2] = '*';
        return;
    }
    int plus = 3*pow(2,n-1);
    makingStar(n-1,i,j);
    makingStar(n-1,i+plus,j-plus);
    makingStar(n-1,i+plus,j+plus);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    for(int i = 0;i<3080;++i)
    {
        for(int j = 0;j<6160;++j)
        {
            star[i][j] = ' ';
        }
    }

    int k = 0;
    cin>>N;
    for(int i = 1;i<=10;++i)
    {
        if(pow(2,i) == N/3)
        {
            k = i;
            break;
        }
    }

    makingStar(k,0,N-1);

    for(int i = 0;i<N;++i)
    {
        for(int j = 0;j<2*N;++j)
        {
            cout<<star[i][j];
        }
        cout<<'\n';
    }

    return 0;
}