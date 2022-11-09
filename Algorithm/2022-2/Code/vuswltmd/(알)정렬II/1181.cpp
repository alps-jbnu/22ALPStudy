#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;
vector<string> word;

bool cmp(string a, string b)
{
	if (a.length() < b.length())
	{
		return true;
	}
	else if (a.length() > b.length())
	{
		return false;
	}
	else
	{
		if (a < b)
		{
			return true;
		}
		else if(a > b)
		{
			return false;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string st;
		cin >> st;
		word.push_back(st);
	}

	sort(word.begin(), word.end(), cmp);
	
	word.erase(unique(word.begin(), word.end()), word.end());

	for (auto i = word.begin(); i != word.end(); i++)
	{
		cout << *i << '\n';
	}
}