#define MX_N 201
#define INT_MX 2000001

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
double shortest[MX_N][MX_N];
double longest[MX_N][MX_N];
double max_time[MX_N];

void init()
{
    for (int i{}; i < MX_N; i++)
    {
        for (int j{}; j < MX_N; j++)
        {
            if (i == j)
                continue;
            shortest[i][j] = INT_MX;
        }
    }
}

void show()
{
    cout << '\n';
    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            cout << shortest[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    init();
    cin >> n >> m;

    for (int i{}; i < m; i++)
    {
        int s, e;
        double l;
        cin >> s >> e >> l;
        shortest[s][e] = min(shortest[s][e], l);
        shortest[e][s] = min(shortest[e][s], l);
        longest[s][e] = max(longest[s][e], l);
        longest[e][s] = max(longest[e][s], l);
    }

    for (int i{1}; i <= n; i++)
    {
        for (int s{1}; s <= n; s++)
        {
            for (int e{1}; e <= n; e++)
            {
                if (shortest[s][e] > shortest[s][i] + shortest[i][e])
                {
                    shortest[s][e] = shortest[s][i] + shortest[i][e];
                }
            }
        }
    }

    //show();

    for (int i{1}; i <= n; i++)
    {
        for (int s{1}; s <= n; s++)
        {
            for (int e{1}; e <= n; e++)
            {
                double cur_time{max(shortest[i][s], shortest[i][e])};
                double left_length{longest[s][e] - abs(shortest[i][s] - shortest[i][e])};
                if (left_length > 0)
                    cur_time += left_length / 2;
                max_time[i] = max(max_time[i], cur_time);
            }
        }
    }

    printf("%.1f\n", *min_element(max_time + 1, max_time + n + 1));
    //cout << *min_element(max_time + 1, max_time + n + 1);

    return 0;
}