#include <iostream>
const int MAX = 10000 + 1;
using namespace std;

int n, i;
int arr[MAX];

int MomPartition(int* arr, int l, int r, int M)
{
	for (int cnt = l; cnt <= r; cnt++)
	{
		int idx = M;
	}
	
	int temp = arr[idx];
	arr[idx] = arr[r];
	arr[r] = temp;

	return partition(arr, l, r);
}

int partition(int* arr, int l, int r)
{
	int pivot = arr[r];
	int x = l - 1;

	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;

	return i + 1;
}

int Quickselect(int* arr, int l, int r, int i)
{
	if (l == r) return arr[l];

	int p = partition(arr, l, r);
	int k = p - l + 1;

	if (i < k) return Quickselect(arr, l, p - 1, i);
	else if (i == k) return arr[p];
	else return Quickselect(arr, p + 1, r, i - k);
}

int main(void) 
{
	cin >> n >> i;
	for (int cnt = 1; cnt <= N; cnt++)
	{
		cin >> arr[cnt];
	}

	return 0;
}