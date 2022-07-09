#include <iostream>
#include <queue>
#include <vector>
#define P 0
#define M 1
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int,vector<int>,greater<int>> q[2];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0) q[P].push(temp);
		else if (temp < 0) q[M].push(-temp);
		else
		{
			int sel_n[2] = { 1,-1 };
			int sel;
			switch (q[M].empty() + q[P].empty())
			{
			case 0:
				sel = q[P].top() >= q[M].top();
				cout << sel_n[sel]*q[sel].top() << "\n";
				q[sel].pop();
				break;
			case 1:
				sel = q[P].empty();
				cout << sel_n[sel]*q[sel].top() << "\n";
				q[sel].pop();
				break;
			default:
				cout << 0 << "\n";
				break;
			}		
		}
	}
}