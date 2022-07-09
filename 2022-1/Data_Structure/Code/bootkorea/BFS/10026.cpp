#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N;
char arr[MAX][MAX];
bool Visited[MAX][MAX];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void BFS(int y, int x, bool Greenless)
{
	queue<pair<int, int>> q;
	char color = arr[y][x];
	
	q.push({ y, x });
	Visited[y][x] = true;
	
	while(!q.empty())
	{
		int my = q.front().first;
		int mx = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int ny = my + dy[i];
			int nx = mx + dx[i];
			
			if(0 <= ny && ny < N && 0 <= nx && nx < N)
			{
				if(Greenless == false)
				{
					if(arr[ny][nx] == color && !Visited[ny][nx])
					{
						Visited[ny][nx] = true;
						q.push({ ny, nx });
					}
				}
				if(Greenless == true)
				{
					if(color == 'R' || color == 'G')
					{
						if(!Visited[ny][nx] && (arr[ny][nx] == 'R' || arr[ny][nx] == 'G'))
						{
							Visited[ny][nx] = true;
							q.push({ ny, nx });
						}
					}
					else if(color == 'B')
					{
						if(!Visited[ny][nx] && (arr[ny][nx] == 'B'))
						{
							Visited[ny][nx] = true;
							q.push({ ny, nx });
						}
					}
				}
			}
		}
	}
}

int main() 
{
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	int result = 0;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(Visited[i][j] == false)
			{
				BFS(i, j, false);
				result++;
			}
		}
	}
	cout << result << " ";
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			Visited[i][j] = false;
		}
	}
	
	result = 0;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(Visited[i][j] == false)
			{
				BFS(i, j, true);
				result++;
			}
		}
	}
	cout << result;
	
	return 0;
}