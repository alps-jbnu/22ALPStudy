#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1;
	string str2;

	cin >> str1;
	cin >> str2;
	int ans = d[0][0];

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i-1] == str2[j-1]) 
				d[i][j]=d[i-1][j-1] + 1;
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
			ans = max(d[i][j], ans);
		}
	}

	cout << ans;
	

}