#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int answer[1002][1002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) answer[i+1][j+1] = answer[i][j] + 1;
            else answer[i+1][j+1] = max(answer[i][j+1], answer[i+1][j]);
        }
    }
    cout << answer[s1.length()][s2.length()];
    return 0;
}