#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		int alpha[26] = { 0, };
		string arr1;
		string arr2;
		cin >> arr1 >> arr2;

		for (auto c : arr1) alpha[c - 'a']++;

		for (auto c : arr2) alpha[c - 'a']--;

		bool isPossible = true;
		for (int i = 0; i < 26; i++){
			if (alpha[i] != 0)isPossible = false;
		}

		if (isPossible) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}
		

	return 0;
}