#include <iostream>

using namespace std;

int Z(int n, int r, int c)
{
	if (n == 0) return 0;
	int dir_way = 1 << (n - 1);
	if (dir_way > r && dir_way > c) return Z(n - 1, r, c);
	if (dir_way > r && dir_way <= c) return Z(n - 1, r, c - dir_way)+dir_way*dir_way;
	if (dir_way <= r && dir_way > c) return Z(n - 1, r - dir_way, c) + 2 * dir_way * dir_way;
	if (dir_way <= r && dir_way <= c) return Z(n - 1, r - dir_way, c - dir_way) + 3 * dir_way * dir_way;
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << Z(n, r, c);
}