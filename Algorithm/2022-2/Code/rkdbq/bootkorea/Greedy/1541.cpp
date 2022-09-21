#include <iostream>
#include <cstring>
using namespace std;

string str;
string temp = "";
int b = 0, m = 0;

void Solve()
{
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (b)
			{
				m -= stoi(temp);
			}
			else m += stoi(temp);

			if (str[i] == '-')
			{
				b = 1;
			}

			temp = "";
			continue;
		}
		temp += str[i];
	}
}

int main()
{
	cin >> str;

	Solve();

	cout << m;

	return 0;
}