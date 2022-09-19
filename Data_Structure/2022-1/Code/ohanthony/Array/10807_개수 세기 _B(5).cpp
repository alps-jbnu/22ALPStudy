#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, v, t;
	cin >> n;

	int ptr[201] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		ptr[t + 100]++;
	}
	
	cin >> v;
	cout << ptr[v+100];
		
	return 0;
}