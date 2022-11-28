#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

int N, result = 0;
int arr[MAX];
int dp[MAX];
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	vec.push_back(arr[0]);
	
	int idx = 0;
	
	for(int i = 1; i < N; i++)
	{
		if(vec[idx] < arr[i])
		{
			vec.push_back(arr[i]);
			idx++;
		}
		else
		{
			int num = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
			vec[num] = arr[i];
		}
	}
	
	cout << vec.size();
	
	return 0;
}