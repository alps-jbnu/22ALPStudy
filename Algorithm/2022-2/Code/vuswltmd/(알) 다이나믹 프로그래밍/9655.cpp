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

string d[1005];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	d[1] = "SK";
	d[2] = "CY";
	d[3] = "SK";

	for (int i = 4; i <= N; i++)
	{
		if (d[i - 1] == "SK" || d[i - 3] == "SK")
		{
			d[i] = "CY";
		}
		else if (d[i - 1] == "CY" || d[i - 3] == "CY")
		{
			d[i] = "SK";
		}
	}

	cout << d[N] << '\n';
}
