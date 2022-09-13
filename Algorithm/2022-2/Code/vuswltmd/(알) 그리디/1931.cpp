#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

pair<int, int> arr[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].second; // 시작하는 시간
		cin >> arr[i].first; // 끝나는 시간
	}
	
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first <<" "<< arr[i].second; // 끝나는 시간
		cout << endl;
	}

	int t = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (t > arr[i].second) continue; 
		count++;
		t = arr[i].first; //끝나는 시간
	}

	cout << count;

}