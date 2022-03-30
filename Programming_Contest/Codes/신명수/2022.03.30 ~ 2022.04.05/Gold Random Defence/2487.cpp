#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int gcd(int a, int b)
{
	if(b > a) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a%b);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n+1, 0);
	for(int i=1;i<=n;i++)
		cin >> v[i];

	vector<bool> check(n+1, false);
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		if(check[i]) continue;
		check[i] = true;
		int cnt = 1;
		int next = v[i];
		while(next != i)
		{
			cnt++;
			check[next] = true;
			next = v[next];
		}
		ans.push_back(cnt);
	}
	int lcm = ans[0];
	for(size_t i=1;i<ans.size();i++)
	{
		lcm = lcm * ans[i] / gcd(lcm, ans[i]);
	}
	cout << lcm;

	return 0;
}