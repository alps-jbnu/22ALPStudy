#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100000 + 1
using namespace std;

int T, N, cnt = 0;
int arr[MAX];
bool Visited[MAX];
bool Group[MAX];

void DFS(int x)
{
	Visited[x] = true;
	int next = arr[x];
	
	if(!Visited[next])
	{
		DFS(next);
	}
	else if(!Group[next])
	{
		for(int i = next; i != x; i = arr[i])
		{
			cnt++;
		}
		cnt++;
	}
	
	Group[x] = true;
}

int main()
{
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			Visited[i] = false;
			Group[i] = false;
		}
		
		for(int i = 1; i <= N; i++)
		{
			cin >> arr[i];
		}
		cnt = 0;
		
		for(int i = 1; i <= N; i++)
		{
			if(!Visited[i]) DFS(i);
		}
		
		cout << N - cnt << "\n";
		
	}
	
	return 0;
}