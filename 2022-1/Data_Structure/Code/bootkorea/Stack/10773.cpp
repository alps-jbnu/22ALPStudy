#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int K, result = 0;
stack<int> st;

int main()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;

		if (num == 0) st.pop();
		else st.push(num);
	}

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	cout << result;

	return 0;
}