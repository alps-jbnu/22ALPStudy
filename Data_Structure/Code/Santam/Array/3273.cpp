#include <iostream>

using namespace std;

int num_dic[2000001] = { 0 };
int num[100000] = { 0 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		num_dic[temp]++;
		num[i] = temp;
	}
	int cnt = 0;
	int x;
	cin >> x;
	for (int i = 0;i < n;i++)
	{
		if (x > num[i])
		{
			if (x != num[i] * 2)
			{
				if (num_dic[x - num[i]]) cnt++;
			}
		}
	}
	cout << cnt/2 << endl;
	return 0;
}