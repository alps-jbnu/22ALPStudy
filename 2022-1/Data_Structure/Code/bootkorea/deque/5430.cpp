#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
	int T, num, i;
	string s, str;
	bool reverse, error;

	cin >> T;

	while (T--)
	{
		deque<int> dq;
		reverse = true, error = false;

		cin >> s >> num >> str;

		i = 1;

		while (str[i] != '\0')
		{
			int x = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
				x *= 10;
				x += int(str[i] - '0');
				i++;
			}
			if (x != 0)
			{
				dq.push_back(x);
			}
			i++;
		}
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == 'R')
			{
				reverse = !reverse;
			}
			else if (s[i] == 'D')
			{
				if (dq.empty())
				{
					error = true;
					cout << "error" << "\n";
					break;
				}

				if (reverse) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
			i++;
		}

		if (!error) {
			cout << "[";
		}
		while (!dq.empty())
		{
			if (reverse)
			{
				auto x = dq.front();
				dq.pop_front();
				cout << x;
			}
			else {
				auto x = dq.back();
				dq.pop_back();
				cout << x;
			}
			if (!dq.empty())
			{
				cout << ",";
			}
		}
		if (!error) {
			cout << "]" << "\n";
		}
	}

	return 0;
}