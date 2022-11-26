#define MX_N 100001
#define TASTE_RANGE 1000001

#include <iostream>
#include <algorithm>
using namespace std;

int n, A, B, C;
int segtree[TASTE_RANGE * 4];

void push(int st, int en, int node, int taste, int num_of_candy)
{
	if (st > taste || en < taste)
		return;
	segtree[node] += num_of_candy;
	// cout<<node<<"node: "<<segtree[node]<<'\n';
	if (st == en)
		return;
	int mid{(st + en) / 2};
	push(st, mid, node * 2, taste, num_of_candy);
	push(mid + 1, en, node * 2 + 1, taste, num_of_candy);
}

void pop(int st, int en, int node, int st_priority, int en_prioririty, int find_priority)
{
	if (st_priority <= find_priority && find_priority <= en_prioririty)
	{
		segtree[node] -= 1;

		if (st == en)
		{
			cout << st << '\n';
			return;
		}

		int mid{(st + en) / 2};
		int left_en_priority{st_priority + segtree[node * 2] - 1};
		pop(st, mid, node * 2, st_priority, left_en_priority, find_priority);
		pop(mid + 1, en, node * 2 + 1, left_en_priority + 1, en_prioririty, find_priority);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++)
	{
		cin >> A;
		if (A == 1)
		{
			cin >> B;
			int size{segtree[1]};
			pop(1, TASTE_RANGE - 1, 1, 1, size, B);
		}
		else
		{
			cin >> B >> C;
			push(1, TASTE_RANGE - 1, 1, B, C);
		}
	}

	return 0;
}