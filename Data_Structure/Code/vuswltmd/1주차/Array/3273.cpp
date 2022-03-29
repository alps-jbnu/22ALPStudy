#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <stack>
#include <utility>
using namespace std;

using namespace std;


int main()
{
	int arr[100001] = { 0, };
	int num[2000001] = { 0, };

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int x;
	cin >> x;

	for (int i = 1; i <= n; i++)
	{
		if (num[x - arr[i]] == 1)
		{
			count++;
		}
		else
		{
			num[arr[i]] = 1;
		}
	}

	cout << count;

	return 0;
}