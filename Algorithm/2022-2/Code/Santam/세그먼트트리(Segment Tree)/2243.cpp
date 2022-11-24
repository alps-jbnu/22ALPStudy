#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll board[4000000]{}, v[1000001]{};
int n = 1000000, m;

ll init(int s, int e, int node)
{
	if (s == e) return board[node] = v[s];
	int mid = (s + e) / 2;
	return board[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

ll sea(int s, int e, int node, int idx)
{
	board[node]--; //사탕 하나 빼기에 부분합-1
	if (s == e) return s; //우선순위 맞는 사탕 발견
	int mid = (s + e) / 2;
	if (board[node * 2] >= idx) return sea(s, mid, node * 2, idx); //사탕 부분합 개수 비교
	return sea(mid + 1, e, node * 2 + 1, idx - board[node * 2]); //왼쪽 노드의 부분합을 빼준 idx
}

void update(int s, int e, int node, int idx, ll dif)
{
	if (idx < s || e < idx) return;
	board[node] += dif;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, node * 2, idx, dif);
	update(mid + 1, e, node * 2 + 1, idx, dif);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t, p, q; cin >> t;
		switch (t)
		{
		case 1:
			cin >> p;
			cout << sea(1, n, 1, p) << "\n";
			break;
		default:
			cin >> p >> q;
			update(1, n, 1, p, q);
			break;
		}
	}
	return 0;
}