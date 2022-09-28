#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, cnt;
vector<long long> vec;

void Solve(int num)
{
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);

	cnt = 2;

	while (true)
	{
		vec.push_back(vec[cnt - 1] + vec[cnt]);
		cnt++;

		if (cnt == 91) break;
	}
}

int main()
{
	cin >> N;

	Solve(90);

	cout << vec[N % cnt];

	return 0;
}