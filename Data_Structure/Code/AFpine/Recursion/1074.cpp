#include <bits/stdc++.h>

// 1074 Z

using namespace std;

static const int INF = 1000000000;

int N;
int r,c;

int Z(int i, int j, int n, int result)
{
    if(n == 0)
    {
        return result;
    }
    int pivot = pow(2,n-1);
    if(i < pivot && j < pivot)
    {
        return Z(i,j,n-1,result);
    }
    else if(i < pivot)
    {
        return Z(i,j-pivot,n-1,result+pow(pivot,2));
    }
    else if(j < pivot)
    {
        return Z(i-pivot,j,n-1,result+(pow(pivot,2)*2));
    }
    else
    {
        return Z(i-pivot,j-pivot,n-1,result+(pow(pivot,2)*3));
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>r>>c;

    cout<<Z(r,c,N,0);


    return 0;
}