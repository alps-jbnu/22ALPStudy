#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define tiii tuple<int, int, int>
const int MAX = 1000 + 1;
const int INF = 1e9;
using namespace std;

struct tup
{
	int idx, cnt, val;
};
struct comp
{
	bool operator()(tup& a, tup& b)
	{
		return a.val > b.val;
	}
};

int N, M, K;
int S, D, result = INF, tax = 0;
int arr[MAX][MAX];
vector<tup> vec[MAX];

void Dijkstra()
{
	priority_queue<tup, vector<tup>, comp> pq;
	pq.push({ S, 0, 0 });
	arr[S][0] = 0;

	while (!pq.empty())
	{
		int cur, len, cost;
		cur = pq.top().idx;
		len = pq.top().cnt;
		cost = pq.top().val;
		pq.pop();

		if (arr[cur][len] < cost) continue;

		for (auto it : vec[cur])
		{
			int dest = it.idx;
			int temp = it.val;

			if (arr[dest][len + 1] > temp + cost)
			{
				arr[dest][len + 1] = temp + cost;
				pq.push({ dest, len + 1, temp + cost });
			}
		}
	}
}

void Solve()
{
	result = INF;
	for (int i = 1; i < N; i++)
	{
		result = min(result, arr[D][i] + tax * i);
	}
	cout << result << "\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	cin >> S >> D;

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = INF;

	for (int i = 0; i < M; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		vec[a].push_back({ b, 0, w });
		vec[b].push_back({ a, 0, w });
	}

	Dijkstra();
	Solve();

	while (K--)
	{
		int t; cin >> t; tax += t;
		Solve();
	}
	return 0;
}

//#include <bits/stdc++.h>
//#define ll long long
//#define pii pair<int, int>
//#define pll pair<long long, long long>
//#define tiii tuple<int, int, int>
//const int MAX = 1000 + 1;
//const int INF = 1e9;
//using namespace std;
//
//int N, M, K;
//int S, D, result = INF, tax = 0;
//int arr[MAX][MAX];
//vector<pii> vec[MAX];
//
//void Dijkstra()
//{
//	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
//	pq.push({ S, 0, 0 });
//	arr[S][0] = 0;
//
//	while (!pq.empty())
//	{
//		int cur, len, cost; tie(cur, len, cost) = pq.top();
//		pq.pop();
//
//		if (arr[cur][len] < cost) continue;
//
//		for (auto it : vec[cur])
//		{
//			int dest = it.first;
//			int temp = it.second;
//
//			if (arr[dest][len + 1] > temp + cost)
//			{
//				arr[dest][len + 1] = temp + cost;
//				pq.push({ dest, len + 1, temp + cost });
//			}
//		}
//	}
//}
//
//void Solve()
//{
//	result = INF;
//	for (int i = 1; i < N; i++)
//	{
//		result = min(result, arr[D][i] + tax * i);
//	}
//	cout << result << "\n";
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N >> M >> K;
//	cin >> S >> D;
//
//	for (int i = 1; i <= N; i++)
//		for (int j = 0; j < N; j++)
//			arr[i][j] = INF;
//
//	for (int i = 0; i < M; i++)
//	{
//		int a, b, w; cin >> a >> b >> w;
//		vec[a].push_back({ b, w });
//		vec[b].push_back({ a, w });
//	}
//
//	Dijkstra();
//	Solve();
//
//	while (K--)
//	{
//		int t; cin >> t; tax += t;
//		Solve();
//	}
//	return 0;
//}