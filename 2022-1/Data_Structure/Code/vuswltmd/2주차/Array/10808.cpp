#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int arr[26] = { 0, };
	string al = "abcdefghijklmnopqrstuvwxyz";
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		int j = al.find(str[i]);

		if (j != -1)
		{
			arr[j]++;
		}

	}

	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}

}
