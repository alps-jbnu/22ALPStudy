#include<bits/stdc++.h>
using namespace std;

map<string, int> M_num;
map<int, string> num_M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string monster;
		cin >> monster;

		M_num[monster] = i;
		num_M[i] = monster;
	}

	while (m--) {
		string question;
		cin >> question;

		if (isdigit(question[0])) {
			cout << num_M[stoi(question)] << "\n";
		}
		else cout << M_num[question] << "\n";
	}
	return 0;
}
