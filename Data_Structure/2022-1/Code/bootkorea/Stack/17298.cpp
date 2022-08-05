#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 1000000 + 1
using namespace std;

int N;
vector<int> vec, result;
stack<int> s;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		vec.push_back(x);
	}
	result.assign(vec.size(), -1);

	for (int i = 0; i < vec.size(); i++)
	{
		while (!s.empty() && vec[s.top()] < vec[i])
		{
			result[s.top()] = vec[i];
			s.pop();
		}
		s.push(i);
	}


	for (int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}