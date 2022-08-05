#include <iostream>

using namespace std;

int func2(int arr[], int n)
{
	int arr_num_check[100] = { 0 };
	for (int i = 0;i < n;i++)
	{
		arr_num_check[arr[i] - 1]++;
	}
	for (int i = 0;i < n;i++)
	{
		if (arr_num_check[99 - arr[i]])
		{
			return 1;
		}
	}
	return 0;
	
}

int main()
{
	int arr[1000] = { 0 };
	int num;
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		cin >> arr[i];
	}
	cout<<func2(arr, num);
	return 0;
}