#include <iostream>

using namespace std;

int main()
{
	char char_dic[2][26] = { 0 };
	string fir_word,sec_word;
	cin >> fir_word; cin >> sec_word;

	for (int i = 0;i < fir_word.length();i++)
	{
		char_dic[0][fir_word[i]-'a']++;
	}
	for (int i = 0;i < sec_word.length();i++)
	{
		char_dic[1][sec_word[i]-'a']++;
	}
	int result = 0;
	for (int i = 0;i < 26;i++)
	{
		if (char_dic[0][i] != char_dic[1][i])
		{
			result += abs(char_dic[0][i] - char_dic[1][i]);
		}
	}
	cout << result << endl;
	return 0;
}