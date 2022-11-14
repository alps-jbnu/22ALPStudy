#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	stack < pair<int, int> > st;
	st.push({ 0, 21474836 });
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		while (!st.empty() && num >= st.top().second)
		{
			st.pop();
		}

		count = count + i - st.top().first;
		
		if (st.top().first == 0)
		{
			count--;
		}
		
		st.push({ i, num });
	}

	cout << count;
}

