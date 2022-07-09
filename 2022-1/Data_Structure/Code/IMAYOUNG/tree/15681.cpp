#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, R, Q;
int a, b, x;
int ans[100001];
bool visit[100001];
vector<int> v[100001];

int solve(int now)
{
	visit[now] = true;

	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (!visit[next])
		{
			ans[now] += solve(next);
		}
	}

	return ans[now];
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		ans[i] = 1;

	solve(R);

	for (int i = 0; i < Q; i++)
	{
		cin >> x;
		cout << ans[x] << '\n';
	}

}