#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> pq1;
priority_queue<int> pq2;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		
		if(x == 0)
		{
			if(pq1.empty() && pq2.empty()) cout << "0\n";
			else
			{
				if(pq1.empty())
				{
					cout << pq2.top() << "\n";
					pq2.pop();
				}
				else if(pq2.empty())
				{
					cout << pq1.top() << "\n";
					pq1.pop();
				}
				else
				{
					if(pq1.top() < -(pq2.top()))
					{
						cout << pq1.top() << "\n";
						pq1.pop();
					}
					else
					{
						cout << pq2.top() << "\n";
						pq2.pop();
					}
				}
			}
		}
		else if(x > 0)
		{
			pq1.push(x);
		}
		else
		{
			pq2.push(x);
		}
	}
	
	return 0;
}