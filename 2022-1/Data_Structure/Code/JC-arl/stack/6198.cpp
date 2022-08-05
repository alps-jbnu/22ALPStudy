#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> st;
	long long int N, count = 0;
	cin >> N;
	st.push(0);
	for (int i = 0; i < N; i++)
	{
		int h;
		cin >> h;

		while (!st.empty() && st.top() <= h)
			st.pop();
		
		st.push(h);
		count += st.size() - 1;
	}
	cout << count;

	return 0;
}