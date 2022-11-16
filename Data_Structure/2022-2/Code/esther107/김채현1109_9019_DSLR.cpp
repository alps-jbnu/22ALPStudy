#include <queue>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int a, b;
bool visited[10000];

void bfs()
{
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visited[a] = true;

    while (!q.empty())
    {
        int cur_num = q.front().first;
        string cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            cout << cur_op << '\n';
            return;
        }
		
        int D, S, L, R;
        D = (cur_num * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = true;
            q.push(make_pair(D, cur_op + "D"));
        }
		
        S = cur_num - 1 < 0 ? 9999 : cur_num - 1;
        if (!visited[S])
        {
            visited[S] = true;
            q.push(make_pair(S, cur_op + "S"));
        }

        L = (cur_num % 1000) * 10 + (cur_num / 1000);
        if (!visited[L])
        {
            visited[L] = true;
            q.push(make_pair(L, cur_op + "L"));
        }

        R = cur_num / 10 + (cur_num % 10) * 1000;
        if (!visited[R])
        {
            visited[R] = true;
            q.push(make_pair(R, cur_op + "R"));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> a >> b;
        memset(visited, false, sizeof(visited)); 
        bfs();
    }

    return 0;
}
