#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
	stack<int> st;
	int n, k, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		if (k == 0)
			st.pop();
		else
			st.push(k);
	}
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}