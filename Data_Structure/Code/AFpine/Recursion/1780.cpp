#include <bits/stdc++.h>

// 1780 종이의 개수

using namespace std;

static const int INF = 1000000000;

char paper[2200][2200];
int N;
int plus1 = 0, minus1 = 0, zero = 0;

int checkWB(int x, int y, int k)
{
    int pcheck = 0;
    int mcheck = 0;
    for(int i = x;i<x+k;++i)
    {
        for(int j = y;j<y+k;++j)
        {
            if(paper[i][j] == '1')
            {
                pcheck++;
            }
            else if(paper[i][j] == '2')
            {
                mcheck++;
            }
        }
    }
    if(mcheck == 0 && pcheck == 0)
    {
        return 0;
    }
    else if(pcheck == k*k)
    {
        return 1;
    }
    else if(mcheck == k*k)
    {
        return -1;
    }
    else
    {
        return 2;
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
        minus1++;
        return;
    }
    else if(flag == 1)
    {
        plus1++;
        return;
    }
    else if(flag == 0)
    {
        zero++;
        return;
    }
    else
    {
        makingPaper(i,j,k/3);
        makingPaper(i+k/3,j,k/3);
        makingPaper(i+k/3+k/3,j,k/3);
        makingPaper(i,j+k/3,k/3);
        makingPaper(i+k/3,j+k/3,k/3);
        makingPaper(i+k/3+k/3,j+k/3,k/3);
        makingPaper(i,j+k/3+k/3,k/3);
        makingPaper(i+k/3,j+k/3+k/3,k/3);
        makingPaper(i+k/3+k/3,j+k/3+k/3,k/3);
        return;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    
    int temp;
    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            cin>>temp;
            if(temp == -1)
            {
                paper[i][j] = '2';
            }
            else if(temp == 1)
            {
                paper[i][j] = '1';
            }
            else
            {
                paper[i][j] = '0';
            }
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

    cout<<minus1<<'\n'<<zero<<'\n'<<plus1;

    return 0;
}