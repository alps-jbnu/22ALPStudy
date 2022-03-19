#include <iostream>
#include <stack>
using namespace std;

stack<pair<long long, long long>> st;

int main(void) {
	int N;
	long long first, second;
	long long result = 0;
	cin >> N;

	while (N--)
	{
		cin >> first;
		second = 1;

		if (st.empty())
		{
			st.push({ first, second });
		}
		else
		{
			while (true)
			{
				if (st.empty())
				{
					st.push({ first, second });
					break;
				}
				else if (st.top().first <= first)
				{
					pair<int, int> temp = st.top();
					st.pop();

					result += temp.second;

					if (temp.first == first)
					{
						second += temp.second;
					}
				}
				else if (st.top().first > first)
				{
					st.push({ first, second });
					result++;
					break;
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}