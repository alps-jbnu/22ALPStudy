#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

long long  num[100005];
long long d[100005];

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long n;
	long long m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];

		d[i] = d[i - 1] + num[i];
	}

	while (m--)
	{
		long long a1, a2;
		cin >> a1 >> a2;

		cout << d[a2] - d[a1-1]<< '\n';
	}
	


}