#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 30;

int N;
int lc[MAX], rc[MAX];

// 전위 순회
void PreOrder(int cur)
{
	cout << char(cur + 'A' - 1);
	if (lc[cur] != 0) PreOrder(lc[cur]);
	if (rc[cur] != 0) PreOrder(rc[cur]);
}

// 중위 순회
void InOrder(int cur)
{
	if (lc[cur] != 0) InOrder(lc[cur]);
	cout << char(cur + 'A' - 1);
	if (rc[cur] != 0) InOrder(rc[cur]);
}

// 후위 순회
void PostOrder(int cur)
{
	if (lc[cur] != 0) PostOrder(lc[cur]);
	if (rc[cur] != 0) PostOrder(rc[cur]);
	cout << char(cur + 'A' - 1);
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		char x, y, z;
		cin >> x >> y >> z;

		if (y != '.') lc[x - 'A' + 1] = y - 'A' + 1;
		if (z != '.') rc[x - 'A' + 1] = z - 'A' + 1;
	}

	PreOrder(1); cout << "\n";
	InOrder(1); cout << "\n";
	PostOrder(1);

	return 0;
}