#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int N, result = 0;
vector<pair<int, int>> vec;

void Solve(int idx)
{
    if (idx >= N)
    {
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            if (vec[i].first <= 0) cnt++;
        }

        result = max(result, cnt);
        return;
    }

    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (i == idx) continue;

        if (vec[idx].first > 0 && vec[i].first > 0)
        {
            flag = true;

            vec[idx].first -= vec[i].second;
            vec[i].first -= vec[idx].second;

            Solve(idx + 1);

            vec[idx].first += vec[i].second;
            vec[i].first += vec[idx].second;
        }
    }

    if (!flag) Solve(idx + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vec.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i].first >> vec[i].second;
    }

    Solve(0);

    cout << result;

    return 0;
}