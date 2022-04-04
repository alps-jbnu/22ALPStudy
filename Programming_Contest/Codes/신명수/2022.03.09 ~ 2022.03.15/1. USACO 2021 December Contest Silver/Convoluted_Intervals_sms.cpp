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
 
	int n, k;
	cin >> n >> k;
	vector<int> start(k+1, 0), end(k+1, 0);
	int s, e;
	for(int i=0;i<n;i++)
	{
		cin >> s >> e;
		start[s]++;
		end[e]++;
	}
	vector<int> res(2*k+2, 0);
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=k;j++)
		{
			res[i+j] += start[i] * start[j];
			res[i+j+1] -= end[i] * end[j];
		}
	}
	int ans = 0;
	k += k;
	for(int i=0;i<=k;i++)
	{
		ans += res[i];
		cout << ans << endl;
	}

	return 0;
}
