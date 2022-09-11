#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int N, M;
int arr[MAX], result[MAX];
bool Visited[MAX];

void Solve(int start, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }
    int temp = -1;

    for (int i = start; i < N; i++)
    {
        if (!Visited[i] && temp != arr[i])
        {
            Visited[i] = true;
            result[cnt] = arr[i];
            temp = arr[i];

            Solve(i, cnt + 1);
            Visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    Solve(0, 0);

    return 0;
}