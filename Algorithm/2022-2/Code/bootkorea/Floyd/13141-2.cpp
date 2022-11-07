#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 200 + 1;
const int NUM = 20000 + 100;
const int INF = 1e9;
using namespace std;

int N, M, result = INF;
int arr[MAX][MAX];
int s[NUM], e[NUM], l[NUM];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	memset(arr, 0x3f, sizeof(arr));
	for (int i = 1; i <= N; i++) arr[i][i] = 0;

	for (int i = 1; i <= M; i++)
	{
		cin >> s[i] >> e[i] >> l[i];

		arr[s[i]][e[i]] = min(arr[s[i]][e[i]], l[i]);
		arr[e[i]][s[i]] = min(arr[e[i]][s[i]], l[i]);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 1; i <= N; i++)
	{
		int mx = 0;
		for (int j = 1; j <= M; j++) mx = max(mx, arr[i][s[j]] + arr[i][e[j]] + l[j]);
		result = min(result, mx);
	}

	double answer = (double)result;

	cout << fixed;
	cout.precision(1);
	cout << answer / 2;

	return 0;
}