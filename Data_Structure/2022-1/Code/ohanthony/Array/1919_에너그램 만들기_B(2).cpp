#include<bits/stdc++.h>
using namespace std;

int alpha1[26];
int alpha2[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) alpha1[a[i] - 'a']++; // 각 단어의 알파벳 숫 계산
	for (int i = 0; i < b.length(); i++) alpha2[b[i] - 'a']++;

	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha1[i] != alpha2[i]) {
			// 각 단어의 알파벳 수가 다를때 각 단어의 알파벳 차의 절댓값의 합들이 서로 애너그램 관계에 있도록 함
			count += abs(alpha1[i] - alpha2[i]);
		}
	}
	cout << count;
	return 0;
}

