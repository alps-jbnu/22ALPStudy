#include<iostream>
#include<string>
#include<math.h>
#define MAX 9
using namespace std;
int N, M;
int arry[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arry[i] << ' ';

        cout << "\n";

        return;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                arry[cnt] = i;
                dfs(cnt + 1);
                visited[i] = false;
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dfs(0);
}