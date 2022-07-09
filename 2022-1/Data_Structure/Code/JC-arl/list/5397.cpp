#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string s;
	
	while (n--)
	{
		list<char> L;
		cin >> s;
		//L.assign(s.size(), 0);
		list<char>::iterator cursor = L.begin();
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '<')
			{
				if (L.begin() != cursor)
					cursor--;
			}
			else if (s[i] == '>')
			{
				if (L.end() != cursor)
					cursor++;
			}
			else if (s[i] == '-')
			{
				if (cursor != L.begin())
				{
					cursor--;
					cursor = L.erase(cursor);

				}
			else {
				L.insert(cursor, s[i]);
			}
		}
		for (auto i : L)
			cout << i;
		cout << "\n";

	}


	return 0;
}