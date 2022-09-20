#include <iostream>
#include <algorithm>
using namespace std;

int N, result = 0;
bool arr[15][15];

bool Possible(int i, int num)
{
	int x, y;

	for (x = 0; x < num; x++) // 그 행 전부 탐색
	{
		if (arr[i][x] == true) return false;
	}

	for (x = num - 1, y = i - 1; y >= 0; x--, y--) // 좌상->우하 대각선 탐색
	{
		if (arr[y][x] == true) return false;
	}

	for (x = num - 1, y = i + 1; y < N; x--, y++) // 우상 -> 좌하 대각선 탐색
	{
		if (arr[y][x] == true) return false;
	}

	return true;
}

void Solve(int num)
{
	if (num == N) // 종료 조건!
	{
		result++;
		return;
	}

	for (int i = 0; i < N; i++) // 체스판 배열
	{
		if (!arr[i][num] && Possible(i, num)) // 빈 배열이며 좌표가 등록되지 않은 곳이면
		{
			arr[i][num] = true; // 배열 칸 들어있으며
			Solve(num + 1); // 다음 열 탐색을 진행해주고
			arr[i][num] = false; // 전부 끝나서 놓을 곳 없으면 다시 돌아와 배열 리셋
		}
	}
}

int main()
{
	cin >> N;

	Solve(0);

	cout << result;

	return 0;
}