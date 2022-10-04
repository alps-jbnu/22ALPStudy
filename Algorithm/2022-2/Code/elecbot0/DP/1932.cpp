#include <bits/stdc++.h>

using namespace std;

int N;
int triangle[502][502];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fill(triangle[0], triangle[0]+502, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    int m = triangle[1][1];
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i + 1; j++) {
            if (j == 1) {
                triangle[i+1][j] += triangle[i][j];
            } else if (j == i + 1) {
                triangle[i+1][j] += triangle[i][j-1];
            } else {
                triangle[i+1][j] += max(triangle[i][j], triangle[i][j - 1]);
            }
            if (i == N - 1) {
                m = max(m, triangle[i + 1][j]);
            }
        }
    }
    cout << m;
    return 0;
}