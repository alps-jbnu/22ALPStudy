#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N;
long long cnt = 0;
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		long long temp;
		cin >> temp;
		
		while (!st.empty() && st.top() <= temp)
		{
			st.pop();
		}

		cnt += st.size();

		st.push(temp);
	}
	cout << cnt;

	return 0;
}