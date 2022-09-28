#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#define constant 1000000000
using namespace std;

int main()
{
    int N;
    long long result = 0;
    long long arr[101][11];

    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        arr[i][0] = arr[i - 1][1];
        arr[i][10] = 0;

        for (int j = 1; j <= 9; j++)
        {
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % constant;
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        result += arr[N][i];
    }

    cout << result % constant << "\n";

    return 0;
}
