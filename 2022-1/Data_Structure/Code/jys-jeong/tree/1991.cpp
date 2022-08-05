#include<bits/stdc++.h>
using namespace std;

char p[27];
char num[27];
char lc[27];
char rc[27];
void fronttree(int n) {
	cout << (char)(n+'A');
	if (lc[n] != '.' && lc[n] != 0)	fronttree(lc[n] - 'A');
	if (rc[n] != '.' && rc[n] != 0)	fronttree(rc[n] - 'A');
}

void middletree(int n) {
	if (lc[n] != '.' && lc[n] != 0)	middletree(lc[n] - 'A');
	cout << (char)(n + 'A');
	if (rc[n] != '.' && rc[n] != 0)	middletree(rc[n] - 'A');
}
void endtree(int n) {
	if (lc[n] != '.' && lc[n] != 0)	endtree(lc[n] - 'A');
	if (rc[n] != '.' && rc[n] != 0)	endtree(rc[n] - 'A');
	cout << (char)(n + 'A');
}


int main() {
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >>c;
		lc[a - 'A'] = b;
		rc[a - 'A'] = c;
	}

	fronttree(0);
	cout << "\n";
	middletree(0);
	cout << "\n";
	endtree(0);

	
}