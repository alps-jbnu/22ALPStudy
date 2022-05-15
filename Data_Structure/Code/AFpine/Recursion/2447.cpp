#include <bits/stdc++.h>

// 2447 별 찍기 - 10

using namespace std;

static const int INF = 1000000000;

int N;
char star[6562][6562];

void makingStar(int n, int i, int j)
{
    if(n == 0)
    {
        star[i][j] = '*';
        return;
    }
    int plus = (int)pow(3,n-1);
    makingStar(n-1,i,j);
    makingStar(n-1,i,j+plus);
    makingStar(n-1,i,j+plus+plus);
    makingStar(n-1,i+plus,j);
    makingStar(n-1,i+plus,j+plus+plus);
    makingStar(n-1,i+plus+plus,j);
    makingStar(n-1,i+plus+plus,j+plus);
    makingStar(n-1,i+plus+plus,j+plus+plus);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    for(int i = 0;i<6562;++i)
    {
        for(int j = 0;j<6562;++j)
        {
            star[i][j] = ' ';
        }
    }

    cin>>N;
    for(int i = 1;i<=8;++i)
    {
        if(pow(3,i) == N)
        {
            N = i;
            break;
        }
    }

    makingStar(N,0,0);

    for(int i = 0;i<pow(3,N);++i)
    {
        for(int j = 0;j<pow(3,N);++j)
        {
            cout<<star[i][j];
        }
        cout<<'\n';
    }

    return 0;
}