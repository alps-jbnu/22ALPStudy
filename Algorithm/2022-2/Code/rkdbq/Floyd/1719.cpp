#define MX_N 201
#define MX_M 10001

#include <iostream>
#include <algorithm>

using namespace std;

class Info
{
public:
    int total;
    int prev;
    Info()
    {
        total = MX_M * 1000;
        prev = 0;
    }
};

int n, m;
Info table[MX_N][MX_N];

int ansTable[MX_N][MX_N];
int makeAns(int from, int to)
{
    if (from == table[from][to].prev)
        return to;
    else
        return makeAns(from, table[from][to].prev);
}

void showAnsTable()
{
    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            if (ansTable[i][j] == -1)
                cout << "- ";
            else cout << ansTable[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i{1}; i <= n; i++)
        for (int j{1}; j <= n; j++)
            if (i == j)
                table[i][j].total = 0;

    for (int i{}; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (table[from][to].total > cost)
        {
            table[from][to].total = cost;
            table[from][to].prev = from;
        }
        if (table[to][from].total > cost)
        {
            table[to][from].total = cost;
            table[to][from].prev = to;
        }
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            for (int k{1}; k <= n; k++)
            {
                if (table[j][i].total + table[i][k].total < table[j][k].total)
                {
                    table[j][k].total = table[j][i].total + table[i][k].total;
                    table[j][k].prev = i;
                }
            }
        }
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            if (i == j)
                ansTable[i][j] = -1;
            else
                ansTable[i][j] = makeAns(i, j);
        }
    }

    showAnsTable();

    return 0;
}