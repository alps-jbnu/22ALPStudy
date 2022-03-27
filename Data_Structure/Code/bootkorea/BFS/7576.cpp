#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define MAX 1001
using namespace std;

struct Tomato{
	int y, x;
};
int ydir[4] = {1, 0, -1, 0};
int xdir[4] = {0, 1, 0, -1};

int N, M, result = 0;
int arr[MAX][MAX];
queue<Tomato> q;

bool IsTrue(int ny, int nx)
{
	return (0 <= ny && 0 <= nx && ny < N && nx < M);
}

void BFS()
{
	while(!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int cy = y + ydir[i];
			int cx = x + xdir[i];
			
			if(IsTrue(cy, cx) == 1 && arr[cy][cx] == 0)
			{
				arr[cy][cx] = arr[y][x] + 1;
				q.push({ cy, cx });
			}
		}
	}
}

int main()
{
	scanf("%d %d", &M, &N);
	
	for(int i = 0; i < N; i++) // 세로
	{
		for(int j = 0; j < M; j++) // 가로
		{
			scanf("%d", &arr[i][j]);
			
			if(arr[i][j] == 1) 
			{
				q.push({ i, j });
			}
		}
	}
	
	BFS();
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(arr[i][j] == 0)
			{
				printf("-1");
				return 0;
			}
			
			if(result < arr[i][j])
			{
				result = arr[i][j];
			}
		}
	}
	printf("%d", result - 1);
	
	return 0;
}