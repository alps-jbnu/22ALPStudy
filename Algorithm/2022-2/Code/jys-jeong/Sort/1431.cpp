#include<bits/stdc++.h>
using namespace std;


int n;
string arr[52];

bool compare(string a, string b) {
	if (a.length() != b.length())	return a.length() < b.length();
	int suma = 0, sumb = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9')	suma += a[i] - '0';
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] >= '0' && b[i] <= '9')	sumb += b[i] - '0';
	}
	if (suma != sumb)	return suma < sumb;
	return a < b;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];

	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}
