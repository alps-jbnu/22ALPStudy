#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	int len, count = 0 , arr[26] = { 0 };
	//if (s1.size() > s2.size()) len = s1.size();
	//else len = s2.size();

	for (int i = 0; i < s1.size(); i++)
	{
		arr[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		arr[s2[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != 0)
		{
			if (arr[i] < 0)
			{
				while (arr[i])
				{
					arr[i]++;
					count++;
				}
			}
			else
			{
				while (arr[i])
				{
					arr[i]--;
					count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}
/*
이중 반복 가능
입력
*/