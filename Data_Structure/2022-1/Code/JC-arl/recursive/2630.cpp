#include<iostream>

using namespace std;
int arr[200][200];
int cnt[2];		//0-���, 1-�Ķ���
int N;
bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if(arr[x][y] != arr[i][j])
				return false;
	return true;
}

void paper(int x, int y, int z)
{
	if (check(x, y, z))
	{
		cnt[arr[x][y]]++;
		return;
	}
	int n = z / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			paper(x + i * n, y + j * n, n);
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	paper(0, 0, N);
	for (int i = 0; i < 2; i++)
		cout << cnt[i] << "\n";

	return 0;
}