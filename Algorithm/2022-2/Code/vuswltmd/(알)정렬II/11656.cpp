#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string suffix[1005];

	string word;
	cin >> word;
	suffix[0] = word;

	for (int i = 1; i < word.length(); i++)
	{
		suffix[i] = word.substr(i);
	}

	sort(suffix, suffix+word.length());

	for (int i = 0; i < word.length(); i++)
	{
		cout << suffix[i] << '\n';
	}
}