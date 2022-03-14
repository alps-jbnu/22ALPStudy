#include <iostream>

using namespace std;

int pre[5001] = { 0 };
int nxt[5001] = { 0 };

int main()
{
	int n, k;
	cin >> n; cin >> k;
	int cusor = 0;

	cout << "<";

	nxt[0] = 1;
	pre[1] = n;
	nxt[n] = 1;
	for (int i = 1;i < n;i++)
	{
		nxt[i] = i + 1;
		pre[i + 1] = i;
	}

	for (int i = 0;i < n-1;i++)
	{
		for (int j = 0;j < k;j++)
		{
			cusor = nxt[cusor];
		}
		nxt[pre[cusor]] = nxt[cusor];
		pre[nxt[cusor]] = pre[cusor];
		cout << cusor << ", ";
	}
	cout << nxt[cusor] << ">";
	return 0;
}