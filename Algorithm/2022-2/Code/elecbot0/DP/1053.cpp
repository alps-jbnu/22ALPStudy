#include <bits/stdc++.h>

using namespace std;

string text;
int dp[52][52];

int answer(int start, int end) {
    if (start >= end) return 0;
    if (dp[start][end] == -1) {
        dp[start][end] = min(min(answer(start+1, end) + 1, answer(start, end-1) + 1), answer(start+1, end-1) + (text[start-1] != text[end-1]));
    }
    return dp[start][end];
}

void switch_char(char& c1, char& c2) {
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> text;
    for (int i = 0; i < 52; i++) {
        fill(dp[i], dp[i]+52, -1);
    }
    int ans = answer(1, text.length());
    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 52; k++) {
                fill(dp[k], dp[k]+52, -1);
            }
            switch_char(text[i], text[j]);
            ans = min(ans, answer(1, text.length()) + 1);
            switch_char(text[i], text[j]);
        }
    }
    cout << ans;
    return 0;
}