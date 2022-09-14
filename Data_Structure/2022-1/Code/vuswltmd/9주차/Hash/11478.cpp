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
	string word;
	cin >> word;

	int word_size = 1;

	unordered_set<string> s;

	while (word_size <= word.size())
	{
		for (int i = 0; i < (int)word.size() - word_size+1; i++)
		{
			s.insert(word.substr(i, word_size));
		}
		word_size++;
	}

	vector<string> v(s.begin(), s.end());

	cout << (int)v.size();
}