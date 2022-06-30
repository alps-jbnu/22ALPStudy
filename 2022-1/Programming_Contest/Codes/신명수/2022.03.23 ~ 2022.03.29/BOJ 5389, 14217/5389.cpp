#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
	int n;
	cin >> n;
	int k = (int)ceil(pow(n, 0.5));
	vector<pii> ans;
	for(int i=1;i<=k;i++)
	{
		if(n % i == 0)
		{
			int a = n/i;
			int b = n/a;
			if((a+b)%2 == 0)
			{
				if(a < b) ans.push_back({(b-a)/2, (a+b)/2});
				else ans.push_back({(a-b)/2, (a+b)/2});
			}
		}
	}
	if(ans.size())
	{
		sort(ans.begin(), ans.end());
		cout << ans[0].first << ' ' << ans[0].second << endl;
	}
	else cout << "IMPOSSIBLE\n";
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--)
	{
		solve();
	}

	return 0;
}