#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[2000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		arr[1000000 + (num)]++;
	}

	for (int i = 0; i < 2000001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i-1000000 << '\n';
		}
	}

	//for(int i = 0; int )
}