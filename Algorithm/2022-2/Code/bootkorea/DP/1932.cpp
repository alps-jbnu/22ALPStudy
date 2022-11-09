#include <iostream>
#include <cmath>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, result = 0;
int Arr[501][501];
int arr[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            Arr[i][j] = arr[i][j] + max(Arr[i - 1][j - 1], Arr[i - 1][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        result = max(result, Arr[N][i]);
    }

    cout << result << "\n";
    return 0;
}