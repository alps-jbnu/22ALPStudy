#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <stack>
#include <utility>
using namespace std;

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int aaa[26] = { 0, };
	int bbb[26] = { 0, };
	int count = 0;


	for (int i = 0; i < a.size(); i++)
	{
		aaa[a[i] - 'a'] ++;
	}

	for (int i = 0; i < b.size(); i++)
	{
		bbb[b[i] - 'a'] ++;
	}

	for (int i = 0; i < 26; i++)
	{

		count = count + abs(aaa[i] - bbb[i]);
	}

	cout << count;

}