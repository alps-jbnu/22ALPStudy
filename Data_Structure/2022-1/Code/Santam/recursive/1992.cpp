#include <iostream>

using namespace std;

int board[64][64] = { 0 };
void Rec(int n, int p_x, int p_y)
{
	if (n == 1)
	{
		cout<< board[p_y][p_x];
		return;
	}
	bool is_all_equal = true;
	int temp_sum = 0;
	for (int i = p_y;i < p_y+n;i++)
	{
		for (int j = p_x;j < p_x+n;j++)
		{
			temp_sum += board[i][j];
		}
	}	
	if (temp_sum != 0 && temp_sum != (n * n)) is_all_equal = false;
	if (is_all_equal)
	{
		cout << board[p_y][p_x];
		return;
	}
	else
	{
		cout << "(";
		Rec(n / 2, p_x, p_y);
		Rec(n / 2, p_x + n / 2, p_y);
		Rec(n / 2, p_x, p_y + n / 2);
		Rec(n / 2, p_x + n / 2, p_y + n / 2);
		cout << ")";
	}
}

int main()
{
	int n;
	cin >> n;
	getchar();
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			board[i][j]=  getchar() - '0';
		}
		getchar();
	}
	
	Rec(n, 0, 0);
	return 0;
}