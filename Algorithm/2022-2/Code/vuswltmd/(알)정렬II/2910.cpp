#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

vector<int> message;
int arr[1000000000]; // 빈도
int arr2[1000000000]; // 먼저 나온 순서

bool cmp(int a, int b)
{
	if (arr[a] > arr[b])
	{
		return true;
	}
	else if(arr[a] <  arr[b])
	{
		return false;
	}
	else
	{
		if (arr2[a] < arr2[b])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int c;

	cin >> n;
	cin >> c;

	int order = 1; //먼저 나온 순서

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		bool check = false;
		for (auto i = message.begin(); i != message.end(); i++)
		{
			if(*i == num)
			{
				check = true;
			}
		}

		message.push_back(num);
		arr[num]++;

		if (check != true)
		{
			arr2[num] = order;
			order++;
		}
	}

	sort(message.begin(), message.end(), cmp);

	for (auto i = message.begin(); i != message.end(); i++)
	{
		cout << *i << ' ';
	}
}