#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, result = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main() 
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	
	while(1)
	{
		if(pq.size() == 1)
		{
			cout << result;
			return 0;
		}
		
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		
		pq.push(x + y);
		result += (x + y);
	}
}