#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int board[2005];
int d[2005][2005];
int N;
int M;
int mid;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	// d[st][en]이 펠린드롭이려면
	// d[st + 1][en - 1]도 펠린드롭이어야 함

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;

		board[i] = num;
		d[i][i] = 1;
		// 자기자신 즉 n번째 인덱스에서 ~ n번째 인덱스까지는 펠린드롭이다.  

		if (i != 1 && board[i - 1] == board[i])
		{
			d[i - 1][i] = 1;
		}

		// 바로 앞 인덱스와 값이 동일하면 펠린드롭이다. 
	}

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = N; j > i; j--)
		{
			if (board[i] == board[j] && d[i + 1][j - 1] == 1)
			{
				d[i][j] = 1;
			}
		}
	}

	// 시간복잡도 O(N^2) 

	// 밑의 주석을 해제하고 돌려보면 알겠지만 
	// 큰 수부터 dp를 채워야하므로 위처럼 역으로 포문을 작성하였다.
	// 역으로 포문을 돌리지 않으면 dp가 제대로 채워지지 않음

	//
	/*for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			cout << "d[" << i << "][" << j << "]: " << d[i][j] << '\n';
		}
	}*/

	cin >> M;

	while (M--)
	{
		int st, en;
		cin >> st >> en;
		cout << d[st][en] << '\n';
	}
}
