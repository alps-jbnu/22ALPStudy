#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, zerocnt, onecnt;
long long result = 0;
vector<int> pos;
vector<int> neg;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num > 1) pos.push_back(num);
		else if (num < 0) neg.push_back(-num);
		else if (num == 0) zerocnt++;
		else onecnt++;
	}

	if (pos.size() % 2 == 1)
	{
		pos.push_back(1);
	}
	if (neg.size() % 2 == 1)
	{
		if (zerocnt == 0) neg.push_back(-1);
		else neg.push_back(0);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	result = onecnt;

	for (int i = 0; i < pos.size(); i += 2)
	{
		result += pos[i] * pos[i + 1];
	}
	for (int i = 0; i < neg.size(); i += 2)
	{
		result += neg[i] * neg[i + 1];
	}

	cout << result;

	return 0;
}