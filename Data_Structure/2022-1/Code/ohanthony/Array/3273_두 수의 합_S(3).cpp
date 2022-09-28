#include<bits/stdc++.h>
using namespace std;

int arr[2000005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x; // n: 수열의 크기
	cin >> n;

	int ptr[100001] = { 0, };
	
	for (int i = 0; i < n; i++)
	{
		cin >> ptr[i];
		arr[ptr[i]]++;
	}

	cin >> x;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (x - ptr[i] > 0)
		{
			if (arr[x - ptr[i]] == 1 && x- ptr[i] != ptr[i])
			{
				count++;
			}
		}
	}

	if (n == 1)
	{
		cout << "0";
	}
	else cout << count / 2;

	return 0;
}