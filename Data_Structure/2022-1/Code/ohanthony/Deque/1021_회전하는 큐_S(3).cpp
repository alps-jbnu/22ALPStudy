#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int count = 0;
	int n, m; // n: 큐의 크기, m: 뽑아내려고 하는 수의 개수
	cin >> n >> m;
	deque<int> d;

	for (int i = 1; i <= n; i++)
		d.push_back(i);

	for (int i = 1; i <= m; i++)
	{
		int num;
		cin >> num;
		
		
		// 찾으려고 하는 원소의 위치를 index에 저장
		auto index = find(d.begin(), d.end(), num) - d.begin(); 
		while (d.front() != num)
		{
			if (index < d.size() - index)
			{
				d.push_back(d.front());
				d.pop_front();
			}
			else
			{
				d.push_front(d.back());
				d.pop_back();
			}
			count++;
		}
		d.pop_front();
	}

	cout << count;
	return 0;
}