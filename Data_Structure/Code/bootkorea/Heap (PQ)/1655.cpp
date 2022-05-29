#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, MAX = 0, MIN = 0;
int arr[100000 + 1];
priority_queue<int> max_pq, min_pq;

int main() 
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	for(int i = 0; i < N; i++)
	{
		if(max_pq.size() > min_pq.size())
		{
			min_pq.push(-arr[i]);
		}
		else max_pq.push(arr[i]);
		
		if(max_pq.empty() == 0 && min_pq.empty() == 0)
		{
			if(max_pq.top() > -min_pq.top())
			{
				MAX = max_pq.top();
				MIN = -min_pq.top();
				
				max_pq.pop();
				min_pq.pop();
				
				max_pq.push(MIN);
				min_pq.push(-MAX);
			}
		}
		
		cout << max_pq.top() << "\n";
	}
	
	return 0;
}