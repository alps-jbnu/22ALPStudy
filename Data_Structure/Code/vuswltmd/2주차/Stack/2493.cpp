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

int n;
stack<pair<int, int>> st; //first..순서 second..높이

int main()
{

	cin >> n;

	
	st.push({ 0 , 100000001});

	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;

		while (st.top().second < height)
		{
			st.pop();
		}

		cout << st.top().first << " ";

		st.push({ i, height });
	}


}