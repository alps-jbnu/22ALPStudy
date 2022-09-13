#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int d[45];
int f_zero[45];
int f_one[45];

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		//d[1] = 1;
		f_zero[1] = 0;
		f_one[1] = 1;

		//d[0] = 0;
		f_zero[0] = 1;
		f_one[0] = 0;

		for (int i = 2; i <= n; i++)
		{
			//d[i] = d[i - 1] + d[i - 2];
			f_zero[i] = f_zero[i - 1] + f_zero[i - 2];
			f_one[i] = f_one[i - 1] + f_one[i - 2];
		}

		cout << f_zero[n] << ' ' << f_one[n] << endl;
	}
}