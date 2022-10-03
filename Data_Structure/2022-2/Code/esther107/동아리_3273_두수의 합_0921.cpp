#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int a = 0, n = 0, x = 0, pair = 0;
	vector <int> arr;
	int number[100001] = { 0 };
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		arr.push_back(a);
		number[a] += 1;
	}
	cin >> x;
	
	for(int i = 0; i < n; i++)
	{
		if(number[x-arr[i]] == 1)
			pair++;
	}
	
	cout << pair/2;
}
