#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int apb[26] = { 0 };//97~122
	for (int i = 0; i < s.size(); i++)
	{
		apb[s[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << apb[i] << " ";
	}
	return 0;
}