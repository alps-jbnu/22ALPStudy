#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int m;
	cin >> m;

	deque<int> arr1; // 1~n까지 수
	vector<int> arr2; // 문제에서 주어진 수
	int cnt = 0;
	int count = 0; // 2,3 조건을 쓴 횟수

	for (int i = 1; i <= n; i++)
	{
		arr1.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		arr2.push_back(num);
	}

	

	while (1)
	{
		if (!arr1.empty() && arr1.front() == arr2[cnt])
		{
			arr1.pop_front();
			cnt++;
			if (cnt == m)
			{
				break;
			}
		}
			else if(!arr1.empty())
			{
				int a = 0;
				int b = 0;
				for (int i = 0; i < arr1.size(); i++)
				{
					a++;
					if (arr1[i] == arr2[cnt])
					{
						
						break;
					}
				}
				for (int i = (arr1.size())-1; i >= 0; i--)
				{
					b++;
					if (arr1[i] == arr2[cnt])
					{
						
						break;
					}
				}

				if (!arr1.empty() && a <= b)
				{
					arr1.push_back(arr1.front());
					arr1.pop_front();
					count++;
				}
				else if (!arr1.empty() && a > b)
				{
					arr1.push_front(arr1.back());
					arr1.pop_back();
					count++;
				}

			}
		
	}

	cout << count;
}