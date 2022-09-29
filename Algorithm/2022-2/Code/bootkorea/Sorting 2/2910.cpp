#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
const int MAX = 100000 + 1;
using namespace std;

int N, C;
vector<pii> vec;

int comp(const pii& x, const pii& y)
{
    return x.first > y.first;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        int t; cin >> t;
        bool idx = 0;

        for (auto& v : vec)
        {
            if (v.second == t)
            {
                idx = 1;
                v.first++;
                break;
            }
        }
        if (!idx) vec.push_back({ 1, t });
    }
    stable_sort(vec.begin(), vec.end(), comp);

    for (auto v : vec)
    {
        while (v.first--)
        {
            cout << v.second << ' ';
        }
    }

    return 0;
}