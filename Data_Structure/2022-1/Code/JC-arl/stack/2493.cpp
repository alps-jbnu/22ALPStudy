#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,height;
	stack<pair<int,int>> st;
	st.push({ 100000001,0 });
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> height;
		while (st.top().first < height)
			st.pop();
		cout << st.top().second << " ";
		st.push({ height,i });
	}
	return 0;
}