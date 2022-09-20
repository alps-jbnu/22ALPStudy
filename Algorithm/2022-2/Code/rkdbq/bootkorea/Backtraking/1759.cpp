#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int L, C;
char word[16];

void DFS(int pos, string str, int vowel, int con)
{
	if (str.size() == L)
	{
		if (vowel >= 1 && con >= 2)
		{
			cout << str << "\n";
			return;
		}
	}

	for (int i = pos; i < C; i++)
	{
		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
		{
			DFS(i + 1, str + word[i], vowel + 1, con);
		}
		else DFS(i + 1, str + word[i], vowel, con + 1);
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> word[i];
	}
	sort(word, word + C);

	DFS(0, "", 0, 0);

	return 0;
}