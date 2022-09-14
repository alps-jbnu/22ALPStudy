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

vector<int> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m;
	cin >> m;

	int l;
	cin >> l;

	arr.push_back(0); arr.push_back(l);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	int low = 1;
	int high = l;
	int mid = 0;
	int result = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		int store = 0;

		for (int i = 1; i < arr.size(); i++)
		{
			int dist = arr[i] - arr[i - 1];

				store += (dist / mid);
			

			if (dist % mid == 0)
			{
				store--;
			}
		}

		if (store <= m)
		{
			high = mid - 1;
			result = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << result << endl;

}