#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int arr[100];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string arr;
	cin >> arr;

	int leng = arr.length();

	int zero = 0;
	int one = 0;

	if (arr[0] == '0')
	{
		zero++;
		for (int i = 1; i < leng; i++)
		{
			if (arr[i] != arr[i - 1])
			{
				if (arr[i] == '1')
				{
					one++;
				}
				else
				{
					zero++;
				}
			}
		}
	}
	else if (arr[0] == '1')
	{
		one++;
		for (int i = 1; i < leng; i++)
		{
			if (arr[i] != arr[i - 1])
			{
				if (arr[i] == '0')
				{
					zero++;
				}
				else
				{
					one++;
				}
			}
		}
	}

	if (one < zero)
	{
		cout << one;
	}
	else
	{
		cout << zero;
	}
}