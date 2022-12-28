#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100000;

int a[MAX + 1];
pair<int, int> tree[MAX * 4];

pair<int, int> init(int start, int end, int node)
{ // 각 노드에 자식 노드의 최댓값, 최솟값을 가지는 세그먼트 트리 구성
	if (start == end)
	{ // 리프 노드 도착 시 최대, 최솟값 저장
		tree[node].first = a[start];
		tree[node].second = a[start];
		return tree[node];
	}

	int mid = (start + end) >> 1;
	// 좌측 노드로 이동
	pair<int, int> left = init(start, mid, node * 2);
	// 우측 노드로 이동
	pair<int, int> right = init(mid + 1, end, node * 2 + 1);

	tree[node].first = min(left.first, right.first);
	tree[node].second = max(left.second, right.second);

	return tree[node];
}

pair<int, int> query(int start, int end, int node, int left, int right)
{
	// 범위를 벗어난 경우 선택되지 않도록 INT_MAX, 0 리턴
	if (start > right || end < left) return { INT_MAX, 0 };
	// 범위 내에 완전히 들어온 경우 현재 노드 리턴
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	// 좌, 우측 노드로 이동하며 최대, 최솟값을 구함.
	pair<int, int> l = query(start, mid, node * 2, left, right);
	pair<int, int> r = query(mid + 1, end, node * 2 + 1, left, right);

	pair<int, int> res;
	res.first = min(l.first, r.first);
	res.second = max(l.second, r.second);

	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	init(1, n, 1);

	while (m--)
	{
		int left, right;
		cin >> left >> right;
		pair<int, int> tmp = query(1, n, 1, left, right);
		cout << tmp.first << ' ' << tmp.second << '\n';
	}

}