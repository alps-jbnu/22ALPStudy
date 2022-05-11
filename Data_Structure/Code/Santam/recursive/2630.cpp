#include <iostream>

using namespace std;

int board[128][128] = { 0 };
int res[2] = { 0 };

int Rec(int n,int p_x,int p_y)
{
	if (n == 1)
	{
		res[board[p_x][p_y]]++;
		return board[p_x][p_y];
	}
	int temp;
	int p_x2 = p_x + n / 2;
	int p_y2 = p_y + n / 2;
	temp = Rec(n / 2, p_x, p_y) + Rec(n / 2, p_x2, p_y) + Rec(n / 2, p_x, p_y2) + Rec(n / 2, p_x2, p_y2);
	if (temp == 0 || temp == 4)
	{
		res[temp / 4] -= 3;
		return temp / 4;
	}
	else return 5;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> board[i][j];
		}
	}
	Rec(n, 0, 0);
	cout << res[0] << "\n" << res[1];
}

/*
종이의 개수 문제랑 같은 맥락으로 풀었다. 4개의 영역으로 나눠서 한 영역이 다 같은 색이 아니면 또 4영역으로 나누는 재귀적 구조를 이루고 있다.
1. 먼저 어느 위치의 영역인지 알기 위한 좌표 p_x,p_y를 받고 몇 칸으로 나눠야 될지 알려줄 n을 받아온다.
2. n이 1인 경우엔 그 영역의 색이 곧 그 종이의 색을 나타내기에 결과값에 해당되는 값을 더해준다.
3. n이 2이상인 경우에는 각 영역을 나눠서 각 영역이 무슨 색인지를 재귀함수 Rec를 호출하여 반환값을 받는다.
 4개의 영역이 같은 영역이면 해당하는 값의 중복되어 더해진 수를 빼주고 해당하는 색깔 값 반환
4.만약 각 영역이 서로 다르면 더 큰 범위에서도 영역이 같을 수가 없으므로 예외가 되는 값을 반환 
*/