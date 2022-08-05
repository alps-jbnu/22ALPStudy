#include <bits/stdc++.h>

// 14956 Philosopher's Walk

using namespace std;

static const int INF = 1000000000;

long long n,m;

pair<int,int> walk(long long k, long long x, long long y, long long remain, int turn)
{
    if(k == 0)
    {
        return pair<int,int>(x,y);
    }
    
    long long pivot = (remain-1) / pow(4,k-1);
    //pivot is [0,3]
    remain -= (pow(4,k-1)*pivot);
    long long next = pow(2,k-1);

    if(turn == 0)
    {//standard
        if(pivot == 0)
        {
            return walk(k-1,x,y,remain,1);
        }
        else if(pivot == 1)
        {
            return walk(k-1,x,y+next,remain,turn);
        }
        else if(pivot == 2)
        {
            return walk(k-1,x+next,y+next,remain,turn);
        }
        else
        {
            return walk(k-1,x+next+next-1,y+next-1,remain,-1);
        }
    }
    else if(turn == 2)
    {
        if(pivot == 0)
        {
            return walk(k-1,x,y,remain,-1);
        }
        else if(pivot == 1)
        {
            return walk(k-1,x,y-next,remain,turn);
        }
        else if(pivot == 2)
        {
            return walk(k-1,x-next,y-next,remain,turn);
        }
        else
        {
            return walk(k-1,x-next-next+1,y-next+1,remain,+1);
        }
    }
    else if(turn > 0)
    {//right turn
        if(pivot == 0)
        {
            return walk(k-1,x,y,remain,0);
        }
        else if(pivot == 1)
        {
            return walk(k-1,x+next,y,remain,turn);
        }
        else if(pivot == 2)
        {
            return walk(k-1,x+next,y+next,remain,turn);
        }
        else
        {
            return walk(k-1,x+next-1,y+next+next-1,remain,2);
        }
    }
    else
    {//left turn
        if(pivot == 0)
        {
            return walk(k-1,x,y,remain,2);
        }
        else if(pivot == 1)
        {
            return walk(k-1,x-next,y,remain,turn);
        }
        else if(pivot == 2)
        {
            return walk(k-1,x-next,y-next,remain,turn);
        }
        else
        {
            return walk(k-1,x-next+1,y-next-next+1,remain,0);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>n>>m;
    long long k = 0;

    while(pow(2,k) != n)
    {
        k++;
    }

    pair<int,int> result;
    
    result = walk(k,1,1,m,0);
    cout<<result.first<<" "<<result.second<<'\n';

    return 0;
}