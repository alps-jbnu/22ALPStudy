#include<iostream>
#include<stack>

using namespace std;
int arr[1000001];
int ai[1000001];
int main(void)
{
	stack<int> st;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)	cin >> ai[i];

	for (int i = n -1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= ai[i])
			st.pop();
		if (st.empty())
			arr[i] = -1;
		else
			arr[i] = st.top();

		st.push(ai[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;

}