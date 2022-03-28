#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 1000 + 1
using namespace std;

struct dir{
	int y, x;
};

int N, M, result;
int arr[MAX][MAX];
int Visited[MAX][MAX][2];
int ydir[4] = {1, -1, 0, 0};
int xdir[4] = {0, 0, 1, -1};

bool Possible(int ny, int nx)
{
	return (ny >= 0 && ny < N && nx >= 0 && nx < M);
}

int BFS()
{
	queue<pair<pair<int, int>, int>> q;
	q.push( { { 0, 0 }, 1 } );
	
	Visited[0][0][1] = 1;
	
	while(!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();
		
		if(y == N - 1 && x == M - 1)
		{
			return Visited[y][x][block];
		}
		
		for(int i = 0; i < 4; i++)
		{
			int dy = y + ydir[i];
			int dx = x + xdir[i];
			
			if(Possible(dy, dx))
			{
				if(arr[dy][dx] == 1 && block)
				{	
					Visited[dy][dx][block - 1] = Visited[y][x][block] + 1;
					q.push({ { dy, dx }, block - 1 });
				}
				
				if(arr[dy][dx] == 0 && Visited[dy][dx][block] == 0)
				{
					Visited[dy][dx][block] = Visited[y][x][block] + 1;
					q.push({ { dy, dx }, block });
				}
			}
		}
	}
	return -1;
}

int main() 
{
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	
	printf("%d", BFS());
	
	return 0;
}