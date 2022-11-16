#include <bits/stdc++.h>
#define MAX 1000 + 1
using namespace std;

int T; // Test Case
int N, K; // N : num of Building, K : Rule
int W; // Finally Build
int delay[MAX], pre[MAX], result[MAX]; // delay: Buildings' build time, pre: One's build rule counts, result: Final Time
vector<int> vec[MAX]; // vector

int main()
{
	cin >> T; // input 1

	while (T--)
	{
		memset(delay, 0, sizeof(delay));
		memset(pre, 0, sizeof(pre));
		memset(result, 0, sizeof(result));

		for (int i = 0; i < MAX; i++)
		{
			vec[i].clear();
		}

		cin >> N >> K; // input 2

		for (int i = 1; i <= N; i++)
		{
			cin >> delay[i]; // delay, input 3
		}

		for (int i = 0; i < K; i++)
		{
			int a, b; cin >> a >> b;
			vec[a].push_back(b); // vec<vec>
			pre[b]++;
		}
		cin >> W; // input 4

		queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			if (!pre[i])
			{
				q.push(i);
				result[i] = delay[i];
			}
		}

		while (!q.empty())
		{
			int num = q.front();
			q.pop();

			for (int next : vec[num])
			{
				result[next] = max(result[next], result[num] + delay[next]);
				pre[next]--;

				if (pre[next] == 0) q.push(next);
			}
		}
		cout << result[W] << "\n";
	}

	return 0;
}