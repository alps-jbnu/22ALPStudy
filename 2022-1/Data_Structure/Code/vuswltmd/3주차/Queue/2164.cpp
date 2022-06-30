#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() > 1)
	{
		q.pop();
		int a = q.front();
		q.pop();
		q.push(a);
	}

	cout << q.front();
}