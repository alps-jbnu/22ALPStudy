#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0);
	list<char> li;
	string init;
	cin >> init;

	for (auto c : init) li.push_back(c);

	int n;
	auto t = li.end();
	cin >> n;

	while (n--)
	{
		char order;
		cin >> order;

		if (order == 'L')
		{
			if (t != li.begin())
				t--;
		}
		else if (order == 'D')
		{
			if (t != li.end())
				t++;
		}
		else if (order == 'B')
		{
			if (t != li.begin())
			{
				t--;
				t = li.erase(t);
			}
		}
		else if (order == 'P')
		{
			char add;
			cin >> add;
			li.insert(t, add);
		}
	}

	for (auto c : li)
		cout << c;
}