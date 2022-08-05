#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string n;
	cin >> n;

	int arr[10] = {0};
	for (int i = 0; i < n.size(); i++)
	{
		int num = n[i] - '0';
		if (num == 6 || num == 9)
		{
			if (arr[6] > arr[9])
				arr[9]++;
			else if (arr[6] < arr[9])
				arr[6]++;
			else
				arr[num]++;
		}
		else
			arr[num]++;
	}
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	cout << max;
	return 0;
}