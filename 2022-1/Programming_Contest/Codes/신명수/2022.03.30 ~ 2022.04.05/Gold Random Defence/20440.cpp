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

	int n;
	cin >> n;
	int s, e;
	vector<int> in, out;
	for(int i=0;i<n;i++)
	{
		cin >> s >> e;
		in.push_back(s);
		out.push_back(e);
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());

	size_t in_idx = 0, out_idx = 0;
	int cnt = 0, ans = 0, sans = 0, eans = 0;
	bool flag = false;
	while(in_idx < in.size())
	{
		if(in[in_idx] < out[out_idx])
		{
			cnt++;
			if(cnt > ans)
			{
				ans = cnt;
				sans = in[in_idx];
				flag = true;
			}
			in_idx++;
		}
		else if(in[in_idx] > out[out_idx])
		{
			if(cnt == ans && flag)
			{
				flag = false;
				eans = out[out_idx];
			}
			cnt--;
			out_idx++;
		}
		else
		{
			in_idx++;
			out_idx++;
		}
	}
	if(out_idx < out.size() && flag) eans = out[out_idx];
	cout << ans << endl;
	cout << sans << ' ' << eans << endl;
	return 0;
}