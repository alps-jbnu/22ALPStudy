#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200 + 1
using namespace std;

int K, W, H;
int arr[MAX][MAX];
bool Visited[MAX][MAX][31];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int kdy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int kdx[8] = { -2, -1, 1, 2, -2, 1, -1, 2 };

int BFS(int y, int x)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push( { { y, x }, { 0, 0 } } );
	Visited[y][x][0] = 1;
	
	while(!q.empty())
	{
		int yy = q.front().first.first;
		int xx = q.front().first.second;
		int knum = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		
		if(yy == H - 1 && xx == W - 1) return cnt;
		
		if(knum < K) // Knight Moves
		{
			for(int i = 0; i < 8; i++)
			{
				int ny = yy + kdy[i];
				int nx = xx + kdx[i];
				
				if(0 <= ny && ny < H && 0 <= nx && nx < W)
				{
					if(!Visited[ny][nx][knum + 1] && !arr[ny][nx])
					{
						Visited[ny][nx][knum + 1] = 1;
						q.push( { { ny, nx }, { knum + 1, cnt + 1 } } );
					}
				}
			}
		}
		
		for(int i = 0; i < 4; i++) // Monkey Moves
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if(0 <= ny && ny < H && 0 <= nx && nx < W)
			{
				if(!Visited[ny][nx][knum] && !arr[ny][nx])
				{
					Visited[ny][nx][knum] = 1;
					q.push( { { ny, nx }, { knum, cnt + 1 } } );
				}
			}
		}
	}
	return -1;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> K >> W >> H;
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	cout << BFS(0, 0);
	
	return 0;
}