#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int N, M;

void Solve(int n, int m, int input[], int output[], int start, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << output[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < n; i++)
    {
        output[cnt] = input[i];
        Solve(n, m, input, output, i, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[MAX], result[MAX];

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    Solve(N, M, arr, result, 0, 0);

    return 0;
}