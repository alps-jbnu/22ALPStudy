#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;
int answer[102][102][102];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2 >> s3;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            for (int k = 0; k < s3.size(); k++) {
                if (s1[i] == s2[j] && s2[j] == s3[k]) {
                    answer[i+1][j+1][k+1] = answer[i][j][k] + 1;
                } else {
                    answer[i+1][j+1][k+1] = max(max(answer[i][j+1][k+1], answer[i+1][j][k+1]), answer[i+1][j+1][k]);
                }
            }
        }
    }
    cout << answer[s1.size()][s2.size()][s3.size()];
    return 0;
}