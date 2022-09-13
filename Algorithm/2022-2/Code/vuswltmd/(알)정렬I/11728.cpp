#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int A_arr[1000005];
int B_arr[1000005];
int C_arr[2000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> A_arr[i];
	for (int i = 0; i < m; i++) cin >> B_arr[i];

	int aind = 0;
	int bind = 0;

	for (int i = 0; i < n + m; i++)
	{
		if (bind == m)
		{
			C_arr[i] = A_arr[aind];
			aind++;
		}
		else if (aind == n)
		{
			C_arr[i] = B_arr[bind];
			bind++;
		}
		else if (A_arr[aind] <= B_arr[bind])
		{
			C_arr[i] = A_arr[aind];
			aind++;
		}
		else
		{
			C_arr[i] = B_arr[bind];
			bind++;
		}
	}

	for (int i = 0; i < n + m; i++)
	{
		cout << C_arr[i] << ' ';
	}


}