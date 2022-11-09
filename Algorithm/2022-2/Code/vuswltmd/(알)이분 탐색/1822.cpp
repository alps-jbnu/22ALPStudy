#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;
int A_arr[500000];
int B_arr[500000];
int C_arr[500000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A;
	int B;
	int count = 0;

	cin >> A >> B;

	for (int i = 0; i < A; i++)
	{
		cin >> A_arr[i];
	}

	for (int i = 0; i < B; i++)
	{
		cin >> B_arr[i];
	}

	sort(B_arr, B_arr + B);

	for (int i = 0; i < A; i++)
	{
		if (binary_search(B_arr, B_arr + B, A_arr[i]) == 0)
		{
			C_arr[count] = A_arr[i];
			count++;
		}
			
	}

	sort(C_arr, C_arr + count);
	cout << count << '\n';

	if (count != 0)
	{
		for (int i = 0; i < count; i++)
		{
			cout << C_arr[i] <<' ';
		}
	}
	
}