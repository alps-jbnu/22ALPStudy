#include <iostream>

using namespace std;

int char_dic[2][26] = { 0 };

int main()
{
	int n;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		string temp_1, temp_2;
		cin >> temp_1; cin >> temp_2;
		for (int j = 0;j < temp_1.length();j++)
		{
			char_dic[0][temp_1[j]-'a']++;
		}
		for (int j = 0;j < temp_2.length();j++)
		{
			char_dic[1][temp_2[j] - 'a']++;
		}
		bool same_chk = true;
		for (int j = 0;j < 26;j++)
		{
			if (char_dic[0][j] != char_dic[1][j])
			{
				same_chk = false;
			}
			char_dic[0][j] = 0;
			char_dic[1][j] = 0;
		}
		if (same_chk) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}

	return 0;
}