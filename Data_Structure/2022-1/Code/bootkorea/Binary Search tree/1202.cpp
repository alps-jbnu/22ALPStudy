#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 300000 + 1
using namespace std;

int N, K;
int weight[MAX];
long long result = 0;
pair<int, int> p[MAX];

int main() 
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	
	for(int i = 0; i < K; i++)
	{
		cin >> weight[i];
	}
	
	sort(p, p + N);
	sort(weight, weight + K);
	
	priority_queue<int> pq;
	
	for(int i, j = 0; i < K; i++)
	{
		while(j < N && p[j].first <= weight[i])
		{
			pq.push(p[j].second);
			j++;
		}
		
		if(!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}
	
	cout << result;
	
	return 0;
}