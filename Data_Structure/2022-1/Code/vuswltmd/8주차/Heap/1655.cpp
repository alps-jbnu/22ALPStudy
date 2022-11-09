#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> pq1; // 큰 것이 탑
	priority_queue<int, vector<int>, greater<int>> pq2; //작은 것이 탑

	int n;
	cin >> n;
	int count = 0;
	

	while (n--)
	{
		int num;
		cin >> num;
		if (pq1.empty() && pq2.empty())
		{
			pq1.push(num);
			cout << pq1.top() << '\n';
		} //둘 다 비어있으면 첫번째 칸에 넣는다
		else if (!pq1.empty() && pq2.empty())
		{
			if (num >= pq1.top())
			{
				pq2.push(num);
				cout << pq1.top() << '\n';
			}
			else if(num < pq1.top())
			{
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(num);
				cout << pq1.top() << '\n';
			}
		}

		else if(!pq1.empty() && !pq2.empty())
		{
			if (pq1.top() > num)
			{
				if (pq1.size() <= pq2.size())
				{
					pq1.push(num);
					cout << pq1.top() << '\n';
				}
				else if (pq1.size() > pq2.size())
				{
					pq2.push(pq1.top());
					pq1.pop();
					pq1.push(num);
					cout << pq1.top() << '\n';
				}
			}
			else if (pq1.top() == num || pq2.top() == num)
			{
				if (pq1.size() <= pq2.size())
				{
					pq1.push(num);
					cout << pq1.top() << '\n';
				}
				else if (pq1.size() > pq2.size())
				{
					pq2.push(num);
					cout << pq1.top() << '\n';
				}
			}
			else if (pq1.top() < num && pq2.top() > num)
			{
				if (pq1.size() <= pq2.size())
				{
					pq1.push(num);
					cout << pq1.top() << '\n';
				}
				else if (pq1.size() > pq2.size())
				{
					pq2.push(num);
					cout << pq1.top() << '\n';
				}
			}
			else if (pq2.top() < num)
			{
				if (pq1.size() <= pq2.size())
				{
					pq1.push(pq2.top());
					pq2.pop();
					pq2.push(num);
					cout << pq1.top() << '\n';
				}
				else if (pq1.size() > pq2.size())
				{
					pq2.push(num);
					cout << pq1.top() << '\n';
				}
			}
		}
		
	}
}