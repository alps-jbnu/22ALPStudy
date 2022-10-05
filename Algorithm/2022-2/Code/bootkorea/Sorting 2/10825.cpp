#include <bits/stdc++.h>
#define MAX 100000 + 1;
using namespace std;

struct S
{
	string str;
	int x, y, z;
};

bool Compare(S x, S y)
{
	if (x.x == y.x)
	{
		if (x.y == y.y)
		{
			if (x.z == y.z)
			{
				return x.str < y.str;
			}
			else return x.z > y.z;
		}
		else return x.y < y.y;
	}
	else return x.x > y.x;
}

int N;
vector<S> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].str >> vec[i].x >> vec[i].y >> vec[i].z;
	}
	sort(vec.begin(), vec.end(), Compare);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].str << "\n";
	}

	return 0;
}