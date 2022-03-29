#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

int N, M;

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

    scanf("%lld %lld", &N, &M);
    vector<vector<int>> v(N+1, vector<int>(M+1, 0));
    set<int> sqaure;
    int ans = -1;
    for(int i=0;i<100000;i++)
    {
        sqaure.insert(i*i);
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            scanf("%1lld", &v[i][j]);
            if(sqaure.find(v[i][j]) != sqaure.end()) ans = max(ans, v[i][j]);
        }
    }
    for(int y=1;y<=N;y++)
    {
        for(int yc=-N;yc<=N;yc++)
        {
            for(int x=1;x<=M;x++)
            {
                for(int xc=-M;xc<=M;xc++)
                {
                    if(yc == 0 && xc == 0) continue;
                    int ty = y, tx = x, tmp = v[ty][tx];
                    while(ty+yc <= N && tx+xc <= M && ty+yc >= 1 && tx+xc >= 1)
                    {
                        ty += yc;
                        tx += xc;
                        tmp *= 10;
                        tmp += v[ty][tx];
                        if(sqaure.find(tmp) != sqaure.end()) ans = max(ans, tmp);
                    }
                }
            }
        }
    }
    cout << ans;
	return 0;
}