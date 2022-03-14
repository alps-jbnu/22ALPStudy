#include <iostream>

using namespace std;

int main()
{
	int AtoZ_num[26] = { 0 };
	string n;
	cin >> n;
	for (int e : n)
	{
		AtoZ_num[e - 'a']++;
	}
	for (int e:AtoZ_num)
	{
		cout << e << " ";
	}
	return 0;
}