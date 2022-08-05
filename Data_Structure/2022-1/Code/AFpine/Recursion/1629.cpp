#include <bits/stdc++.h>

// 1629 곱셈

using namespace std;

static const int INF = 1000000000;

int A,B,C;

long long multiple(int a, int b)
{
    long long res;
    if(b == 0)
    {
        return res = 1;
    }
    if(b == 1)
    {
        return res = a;
    }
    if(b % 2 == 0)
    {//evem
        return res = (multiple(a,b/2) * multiple(a,b/2)) % C;
    }
    else
    {//odd
        return res = (((multiple(a,b/2) * multiple(a,b/2)) % C)*a) % C;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>A>>B>>C;
    
    cout<<multiple(A,B)%C;

    return 0;
}