#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


int solve()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	if(n == 1) return 0;
	int ans = 0;
	for(int i=1;i<n-1;i++)
	{
	    if(v[i] > v[i-1])
	    {
	        int k = v[i]-v[i-1];
	        v[i+1] -= k;
	        ans += k+k;
	        v[i] = v[i-1];
	    }
	}
	if(v[n-1] > v[n-2] || v[n-1] < 0 || v[0] > v[1]) return -1;
	reverse(v.begin(), v.end());
	for(int i=1;i<n-1;i++)
	{
	    if(v[i] > v[i-1])
	    {
	        int k = v[i]-v[i-1];
	        v[i+1] -= k;
	        ans += k+k;
	        v[i] = v[i-1];
	    }
	}
	return ans;
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
		cout << solve() << endl;
	}

	return 0;
}