#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;

int N;
int Parent[MAX];
bool Visited[MAX];
vector<int> vec[MAX];

void Dfs(int nodenum)
{
    Visited[nodenum] = true;

    for (int i = 0; i < vec[nodenum].size(); i++)
    {
        int next = vec[nodenum][i];

        if (!Visited[next])
        {
            Parent[next] = nodenum;
            Dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }

    Dfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << Parent[i] << "\n";
    }

    return 0;
}
