#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, f;
unordered_map<int, string> pokemonFindToName;
unordered_map<string, int> pokemonFindToNum;
string name, k;
int num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> f;
	for (int i{ 1 }; i <= n; i++) {
		cin >> name;
		pokemonFindToName[i] = name;
		pokemonFindToNum[name] = i;
	}

	for (int i{}; i < f; i++) {
		cin >> k;
		if (k[0] > '0' && k[0] <= '9') cout << pokemonFindToName[stoi(k)] << "\n";
		else cout << pokemonFindToNum[k] << "\n";
	}

	return 0;
}