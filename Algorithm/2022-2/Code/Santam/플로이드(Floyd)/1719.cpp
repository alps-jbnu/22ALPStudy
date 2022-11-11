#include <bits/stdc++.h>

using namespace std;

int board[201][201]{};
int n, m;


int main()
{
	cin.tie(0)->sync_with_stdio(false);
	memset(board, 300000, sizeof(int) * 201 * 201); //가중치의 합으로 나올수있는 최대는 200000이므로 그보다 큰수로 board초기화
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int n1, n2, v;
		cin >> n1 >> n2 >> v;
		board[n1][n2] = v;
		board[n2][n1] = v;
	} //입력

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	} //플로이드(k:거쳐가는 노드 i,j:행,열)

	return 0;
}