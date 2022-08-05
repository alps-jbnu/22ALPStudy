#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100 + 1
using namespace std;

int N, M;
int arr[MAX][MAX];
int Visited[MAX][MAX];
int MAP[MAX][MAX];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void BFS(int y, int x)
{
	Visited[y][x] = 1;
	arr[y][x] = 1;
	
	queue<pair<int, int>> q;
	q.push({ y, x });
	
	while(!q.empty())
	{
		int qy = q.front().first;
		int qx = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int ny = qy + dy[i];
			int nx = qx + dx[i];
			
			if(0 < ny && ny <= N && 0 < nx && nx <= M)
			{
				if(MAP[ny][nx] == 1 && Visited[ny][nx] == 0)
				{
					arr[ny][nx] = arr[qy][qx] + 1;
					Visited[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			scanf("%1d", &MAP[i][j]);
		}
	}
	
	BFS(1, 1);
	
	cout << arr[N][M];
	
	return 0;
}