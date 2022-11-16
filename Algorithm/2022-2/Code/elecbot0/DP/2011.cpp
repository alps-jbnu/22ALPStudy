#include <bits/stdc++.h>

using namespace std;

string text;
int answer[5002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> text;
    answer[0] = 0; answer[1] = 1;
    for (int i = 1; i < text.length(); i++) {
        int prev_num = text[i - 1] - '0';
        int cur_num = text[i] - '0';
        if ((prev_num * 10 + cur_num > 26 || prev_num == 0) && cur_num == 0) {
            answer[text.length()] = 0;
            break;
        }
        if (prev_num * 10 + cur_num > 26 || prev_num == 0) {
            answer[i + 1] += answer[i];
        } else if (cur_num == 0) {
            answer[i + 1] += answer[i - 1];
            if (answer[i - 1] == 0) answer[i + 1] += 1;
        } else {
            answer[i + 1] += answer[i] + answer[i - 1];
            if (answer[i - 1] == 0) answer[i + 1] += 1;
        }
        answer[i + 1] %= 1000000;
    }
    if (text[0] == '0') answer[text.length()] = 0;
    cout << answer[text.length()];
    return 0;
}