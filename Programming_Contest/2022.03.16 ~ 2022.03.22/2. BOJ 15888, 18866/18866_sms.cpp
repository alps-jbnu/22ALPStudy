#include <bits/stdc++.h>

using namespace std;

int main()
{
    
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n+1, {0, 0});
	for(int i=1;i<=n;i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<pair<int, int>> hmnfwd(n+1,{INT_MAX, 0}), hmxbwd(n+2, {0, 0});
	vector<pair<int, int>> pmxfwd(n+1, {0, 0}), pmnbwd(n+2, {INT_MAX, 0});
	for(int i=1;i<=n;i++)
	{
		hmnfwd[i] = hmnfwd[i-1];
		pmxfwd[i] = pmxfwd[i-1];
		if(hmnfwd[i].first > v[i].first && v[i].first > 0)
		{
			hmnfwd[i].first = v[i].first;
			hmnfwd[i].second = i;
		}
		if(pmxfwd[i].first < v[i].second && v[i].second > 0)
		{
			pmxfwd[i].first = v[i].second;
			pmxfwd[i].second = i;
		}
	}

	for(int i=n;i>0;i--)
	{
		hmxbwd[i] = hmxbwd[i+1];
		pmnbwd[i] = pmnbwd[i+1];
		if(hmxbwd[i].first < v[i].first && v[i].first > 0)
		{
			hmxbwd[i].first = v[i].first;
			hmxbwd[i].second = i;
		}
		if(pmnbwd[i].first > v[i].second && v[i].second > 0)
		{
			pmnbwd[i].first = v[i].second;
			pmnbwd[i].second = i;
		}
	}
	
	int ans = -1;
	for(int k=n-1;k>0;k--)
	{
		if(hmnfwd[k].first > hmxbwd[k+1].first && pmxfwd[k].first < pmnbwd[k+1].first)
		{
			ans = max(ans, k);
		}
	}
	cout << ans;

   return 0;
    
}