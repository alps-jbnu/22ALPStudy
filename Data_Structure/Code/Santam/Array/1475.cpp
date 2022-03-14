#include <iostream>

using namespace std;

int main()
{
	int set_num[10] = { 0 };
	int n;
	cin >> n;
	int max = 0;
	for (int i = 1;(n-i) >= 0;i *= 10)
	{
		int temp = (n / i) % 10;
		set_num[temp]++;
	}
	int temp2 = (set_num[6] + set_num[9]);
	if (temp2 % 2)
	{
		set_num[6] = temp2 / 2 + 1;
		set_num[9] = set_num[6];
	}
	else
	{
		set_num[6] = temp2 / 2;
		set_num[9] = set_num[6];
	}
	for (int i = 0;i < 10;i++)
	{
		if (max < set_num[i]) max = set_num[i];
	}
	cout << max << endl;

	return 0;
}