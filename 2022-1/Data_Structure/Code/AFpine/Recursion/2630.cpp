#include <bits/stdc++.h>

// 2630 색종이 만들기

using namespace std;

static const int INF = 1000000000;

char paper[200][200];
int N;
int white = 0;
int blue = 0;

int checkWB(int x, int y, int k)
{
    int check = 0;

    for(int i = x;i<x+k;++i)
    {
        for(int j = y;j<y+k;++j)
        {
            if(paper[i][j] == '1')
            {
                check++;
            }
        }
    }
    if(check == 0)
    {//white
        return -1;
    }
    else if(check == k*k)
    {//blue
        return 1;
    }
    else
    {//not
        return 0;
    }
}

void makingPaper(int i, int j, int k)
{
    if(k == 0)
    {
        return;
    }
    int flag = checkWB(i,j,k);
    if(flag == -1)
    {
        white++;
        return;
    }
    else if(flag == 1)
    {
        blue++;
        return;
    }
    else
    {
        makingPaper(i,j,k/2);
        makingPaper(i+k/2,j,k/2);
        makingPaper(i,j+k/2,k/2);
        makingPaper(i+k/2,j+k/2,k/2);
        return;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    
    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            cin>>paper[i][j];
        }
    }

    // for(int i = 1;i<=N;++i)
    // {
    //     for(int j = 1;j<=N;++j)
    //     {
    //         cout<<paper[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

    makingPaper(1,1,N);

    cout<<white<<'\n'<<blue;

    return 0;
}