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
	vector<int> v;  // n개의 수
	vector<int> v2;
	stack<pair<int, int>> st; // first 순서 , second 숫자;
	st.push({ 0,1000001 });

	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
	}

	v.push_back(0);

	reverse(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && v[i] > st.top().second)
		{
			st.pop();
		}
		
		if (i - st.top().first == i)
			v2.push_back(-1);
		else
		{
			v2.push_back(st.top().second);
		}
		
		st.push({ i, v[i] });
	}

	reverse(v2.begin(), v2.end());

	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
}

