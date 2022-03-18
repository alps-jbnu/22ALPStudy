#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;

int find(vector<int>& parent, int v)
{
	if(parent[v] == v) return v;
	return parent[v] = find(parent, parent[v]);
}

void merge(int u, int v, vector<int>& parent)
{
	u = find(parent, u);
	v = find(parent, v);
	if(u == v) return;
	if(u < v) parent[v] = u;
	else parent[u] = v;
}

int SQUARE(int k)
{
	return k*k;
}

int find_dist(int u, int v, vector<set<int>>& vset)
{
	int ret = LLONG_MAX;
	for(auto it=vset[u].begin();it!=vset[u].end();it++)
	{
		auto lt = vset[v].lower_bound(*it);
		if(lt != vset[v].end()) ret = min(ret, SQUARE((*lt)-(*it)));
		if(lt != vset[v].begin()) ret = min(ret, SQUARE((*(--lt))-(*it)));
	}
	return ret;
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
		int n, m;
		cin >> n >> m;
		vector<int> parent(n+1, 0);
		vector<set<int>> vset(n+1, set<int>());
		for(int i=1;i<=n;i++) parent[i] = i;
		int a, b;
		for(int i=0;i<m;i++)
		{
			cin >> a >> b;
			merge(a, b, parent);
		}
		for(int i=1;i<=n;i++) vset[find(parent, i)].insert(i);
		int start = find(parent, 1), end = find(parent, n);
		int ans = find_dist(start, end, vset);
		for(int i=1;i<=n;i++)
		{
			if(find(parent, i) != i) continue;
			if(find(parent, 1) == find(parent, i)) continue;
			if(find(parent, end) == find(parent, i)) continue;
			ans = min(ans, find_dist(i, 1, vset)+find_dist(i, end, vset));
		}
		cout << ans << endl;
	}
	return 0;
}
