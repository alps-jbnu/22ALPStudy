#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string a, b;
		bool js = false;
		cin >> a >> b;

		int arra[26] = { 0, };
		int arrb[26] = { 0, };

		for (int i = 0; i < a.size(); i++)
		{
			arra[a[i] - 'a']++;
		}

		for (int i = 0; i < b.size(); i++)
		{
			arrb[b[i] - 'a']++;
		}

		if (a.size() != b.size())
		{
			cout << "Impossible" << "\n";
		}
		else
		{
			for (int i = 0; i < 26; i++)
			{
				if (arrb[i] != arra[i])
				{
					js = true;
					break;
				}
			}


			if (js == true)
			{
				cout << "Impossible" << "\n";
			}
			else
			{
				cout << "Possible" << "\n";
			}
		}

	}
}