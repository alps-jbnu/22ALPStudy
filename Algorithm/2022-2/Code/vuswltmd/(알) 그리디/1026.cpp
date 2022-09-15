#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int A_arr[50];
int B_arr[50];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> A_arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> B_arr[i];
	}

	sort(A_arr, A_arr + n);
	reverse(A_arr, A_arr + n);
	sort(B_arr, B_arr + n);

	for (int i = 0; i < n; i++)
	{
		sum += A_arr[i] * B_arr[i];
	}

	cout << sum;

}