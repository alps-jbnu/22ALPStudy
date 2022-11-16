#include <bits/stdc++.h>

using namespace std;

string text;
bool pelin[2502][2502];
int dp[2502];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> text;
    for (int i = text.size() - 1; i >= 0; i--) {
        pelin[i][i] = true;
        for (int j = i + 1; j < text.size(); j++) {
            if (text[i] == text[j]) {
                if (pelin[i + 1][j - 1] || abs(i - j) == 1) pelin[i][j] = true;
            }
        }
    }
    
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (pelin[j][i]) {
                if (!dp[i+1]) dp[i+1] = INT_MAX;
                dp[i+1] = min(dp[i+1], dp[j] + 1); 
            }
        }
    }
    cout << dp[text.size()];
    return 0;
}