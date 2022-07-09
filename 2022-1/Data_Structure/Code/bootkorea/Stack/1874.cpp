#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int N, num, cnt = 0;
stack<int> s;
vector<char> vec;

int main()
{
	cin >> N;
	int arr[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		s.push(i);
		vec.push_back('+');

		while (!s.empty() && s.top() == arr[cnt])
		{
			s.pop();
			vec.push_back('-');
			cnt++;
		}
	}

	if (!s.empty()) cout << "NO";
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << "\n";
		}
	}

	return 0;
}