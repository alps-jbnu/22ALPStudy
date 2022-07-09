#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int result = 0;
int arr1[26], arr2[26];
string x, y;

int main()
{
	cin >> x >> y;

	for (int i = 0; i < x.length(); i++)
	{
		arr1[x[i] - 'a']++;
	}
	for (int i = 0; i < y.length(); i++)
	{
		arr2[y[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] != arr2[i])
		{
			result += abs(arr1[i] - arr2[i]);
		}
	}
	cout << result;
}