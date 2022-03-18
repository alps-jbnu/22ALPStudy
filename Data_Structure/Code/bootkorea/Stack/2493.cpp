#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 500000 + 1
using namespace std;

int N, cnt = 0;
stack<pair<int, int>> st;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		
		while (!st.empty())
		{
			if (temp < st.top().second)
			{
				cout << st.top().first << " ";
				break;
			}
			else
			{
				st.pop();
			}
		}
		if (st.empty()) cout << "0 ";
		st.push({ i, temp });
	}

	return 0;
}