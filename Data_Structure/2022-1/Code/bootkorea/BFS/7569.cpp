#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <cstdio>
#define MAX 101
using namespace std;

int ydir[6] = {1, -1, 0, 0, 0, 0};
int xdir[6] = {0, 0, 1, -1, 0, 0};
int hdir[6] = {0, 0, 0, 0, 1, -1};

int N, M, H, result = 0;
int arr[MAX][MAX][MAX] = { 0 };
queue<tuple<int, int, int>> q;

bool IsTrue(int ny, int nx, int nh)
{
	return (0 <= ny && ny < N && 0 <= nx && nx < M && 0 <= nh && nh < H);
}

void BFS()
{
	while(!q.empty())
	{
		int x, y, h;
		tie(x, y, h) = q.front();
		q.pop();
		
		for(int i = 0; i < 6; i++)
		{
			int cy = y + ydir[i];
			int cx = x + xdir[i];
			int ch = h + hdir[i];
			
			if(IsTrue(cx, cy, ch) == 1 && arr[cx][cy][ch] == 0)
			{
				arr[cx][cy][ch] = arr[x][y][h] + 1;
				q.push(make_tuple(cx, cy, ch));
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &M, &N, &H);
	
	for(int k = 0; k < H; k++)
	{
		for(int i = 0; i < N; i++) // 세로
		{
			for(int j = 0; j < M; j++) // 가로
			{
				scanf("%d", &arr[i][j][k]);
				
				if(arr[i][j][k] == 1) 
				{
					q.push(make_tuple(i, j, k));
				}
			}
		}
	}
	
	BFS();
	
	for(int k = 0; k < H; k++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(arr[i][j][k] == 0)
				{
					printf("-1");
					return 0;
				}
				
				if(result < arr[i][j][k])
				{
					result = arr[i][j][k];
				}
			}
		}
	}
	printf("%d", result - 1);
	
	return 0;
}