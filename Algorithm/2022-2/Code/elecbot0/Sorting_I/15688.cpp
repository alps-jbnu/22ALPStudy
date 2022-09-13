#include <bits/stdc++.h>

using namespace std;

int N;
int num[2000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp; cin >> temp;
        num[temp + 1000000]++;
    }
    for (int i = 0; i < 2000002; i++) {
        if (num[i]) {
            for (int j = 0; j < num[i]; j++) {
                cout << i-1000000 << "\n";
            }
        }
    }
    return 0;
}