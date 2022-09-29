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
    cout << answer[s1.length()][s2.length()] << "\n";
    int test_s1 = s1.length();
    int test_s2 = s2.length();
    char ans_text[1002] = {};
    int ans_index = 0;
    while (test_s1 != 0 && test_s2 != 0) {
        int test = answer[test_s1][test_s2];
        int test_1 = answer[test_s1-1][test_s2];
        int test_2 = answer[test_s1][test_s2-1];
        if (test == test_1) {
            test_s1 -= 1;
        } else if (test == test_2) {
            test_s2 -= 1;
        } else {
            ans_text[ans_index] = s1[test_s1-1];
            ans_index += 1;
            test_s1 -= 1;
            test_s2 -= 1;
        }
    }
    for (int i = ans_index - 1; i >= 0; i--) {
        cout << ans_text[i];
    }
    return 0;
}