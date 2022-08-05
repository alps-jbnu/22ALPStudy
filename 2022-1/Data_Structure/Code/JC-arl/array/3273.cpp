#include<iostream>
#include<vector>
using namespace std;

int arr[1000001], num[1000001];
int main(void)
{
	int n, x, count = 0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++)
	{
		if (x < arr[i])		//x-arr[i] 가 음수일때 예외처리
			continue;
		if (num[x - arr[i]]==0)
			num[arr[i]]++;
		else
			count++;
	}	
	cout << count;
	return 0;
}