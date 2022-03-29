#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	string n;
	cin >> n;
	vector<int> rn;
	double high = 0;
	int arr[10] = { 0, };


	for (int i = 0; i < n.size(); i++)
	{
		rn.push_back(n[i] - '0');
	}

	for (int i = 0; i < rn.size(); i++)
	{
		arr[rn[i]]++;
	}

	if ((arr[9] + arr[6]) % 2 == 0)
	{
		arr[9] = (arr[9] + arr[6]) / 2;
		arr[6] = 0;
	}
	else if ((arr[9] + arr[6]) % 2 != 0)
	{
		arr[9] = ((arr[9] + arr[6]) / 2) + 1;
		arr[6] = 0;
	}

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > high)
		{
			high = arr[i];
		}
	}

	cout << high;

}