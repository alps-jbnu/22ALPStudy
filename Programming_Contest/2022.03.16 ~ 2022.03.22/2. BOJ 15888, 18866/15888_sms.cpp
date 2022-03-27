#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    if(b*b - 4*a*c <= 0)
    {
        cout << "둘다틀렸근";
        return 0;
    }
    
    int cnt = 0;
    for(int i=2;i<=128;i<<=1)
        if(a*i*i + b*i + c == 0) cnt++;
    if(cnt == 2) cout << "이수근";
    else
    {
        cnt = 0;
        for(int i=-100;i<105;i++)
            if(a*i*i + b*i + c == 0) cnt++;
        if(cnt == 2) cout << "정수근";
        else cout <<"둘다틀렸근";
    }

	return 0;
}