#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;

int T, K;
bool Visited[MAX];
priority_queue<int> pq;

int main() 
{
	cin >> T;
	
	while(T--)
	{
		cin >> K;
		priority_queue<pair<int, int>> maxHeap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

		for(int i = 0; i < K; i++)
		{
			int num;
			char ch;
			
			cin >> ch >> num;
			
			if(ch == 'I')
			{
				maxHeap.push({ num, i });
				minHeap.push({ num, i });
				
				Visited[i] = 1;
			}
			else if(ch == 'D')
			{
				if(num == 1)
				{
					while(!maxHeap.empty() && !Visited[maxHeap.top().second])
					{
						maxHeap.pop();
					}
					if(!maxHeap.empty())
					{
						Visited[maxHeap.top().second] = false;
						maxHeap.pop();
					}
				}
				else if(num == -1)
				{
					while(!minHeap.empty() && !Visited[minHeap.top().second])
					{
						minHeap.pop();
					}
					if(!minHeap.empty())
					{
						Visited[minHeap.top().second] = false;
						minHeap.pop();
					}
				}
			}
		}
		
		while(!maxHeap.empty() && !Visited[maxHeap.top().second])
		{
			maxHeap.pop();
		}
		while(!minHeap.empty() && !Visited[minHeap.top().second])
		{
			minHeap.pop();
		}
		
		if(maxHeap.empty() && minHeap.empty())
		{
			cout << "EMPTY" << "\n";
		}
		else
		{
			cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
		}
	}
	
	return 0;
}