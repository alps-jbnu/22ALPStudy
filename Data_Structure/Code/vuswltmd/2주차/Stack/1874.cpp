#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr1; //1~n까지 수 입력
	vector<int> arr2; //문제에서 주어진 수열입력; 
	vector<int> arr3;
	vector<char> arr4; // +, - 기호 입력
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		arr1.push_back(i);
	}

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		arr2.push_back(num);
	}

	for (int i = 1; i <= n; i++)
	{
		arr3.push_back(i);
		arr4.push_back('+');

		while (1)
		{
			
			if (arr3.empty() == true)
			{
				break;
			}
			
			
			if (arr3.back() == arr2[cnt])
			{
				arr3.pop_back();
				arr4.push_back('-');
				cnt++;
			}
			else
			{
				break;
			}
		}
		
	}

	if (arr3.empty() == false)
	{
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < arr4.size(); i++)
		{
			cout << arr4[i] << "\n";
		}
	}
}