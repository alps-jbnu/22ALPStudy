#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main(void) 
{
	int N, M;
	cin >> N >> M;

	unordered_map<string, string> m2t; //¸â¹öÀÇ ÆÀÀÌ¸§
	unordered_map<string, vector<string>> t2m; // ÆÀ¿¡ ¼ÓÇÑ ¸â¹öµé

	while (N--)
	{
		string team;
		int member_num;

		cin >> team >> member_num;

		for (int i = 0; i < member_num; i++)
		{
			string member_name;
			cin >> member_name;

			m2t[member_name] = team;
			t2m[team].push_back(member_name);
		}

		sort(t2m[team].begin(), t2m[team].end());
	}

	for (int i = 0; i < M; i++)
	{
		string word; int num;
		cin >> word >> num;

		if (num == 1)
		{
			cout << m2t[word] << '\n';
		}
		else
		{
			for (int i = 0; i < t2m[word].size(); i++)
			{
				cout << t2m[word][i] << '\n';
			}
		}
	}

}