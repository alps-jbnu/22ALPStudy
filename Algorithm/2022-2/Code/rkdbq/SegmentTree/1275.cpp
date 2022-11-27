#define MX_N 100001
#include <iostream>
using namespace std;

int N, Q;
int x, y, a;
long long b;
long long arr[MX_N];
long long sum_arr[MX_N * 4];

long long init_sum_arr(int st, int en, int node)
{
    if (st == en)
        return sum_arr[node] = arr[st];
    int mid{(st + en) / 2};
    return sum_arr[node] = init_sum_arr(st, mid, node * 2) + init_sum_arr(mid + 1, en, node * 2 + 1);
}

long long find_sum(int st, int en, int node, int from, int to)
{
    if (from > en || to < st)
        return 0;
    if (st >= from && en <= to)
        return sum_arr[node];
    int mid{(st + en) / 2};
    return find_sum(st, mid, node * 2, from, to) + find_sum(mid + 1, en, node * 2 + 1, from, to);
}

void change(int st, int en, int node, int idx, long long changed)
{
    if (st <= idx && en >= idx)
    {
        sum_arr[node] -= arr[idx];
        sum_arr[node] += changed;

        if (st == en)
            return;

        int mid{(st + en) / 2};
        change(st, mid, node * 2, idx, changed);
        change(mid + 1, en, node * 2 + 1, idx, changed);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i{1}; i <= N; i++)
    {
        cin >> arr[i];
    }
    init_sum_arr(1, N, 1);
    for (int i{}; i < Q; i++)
    {
        cin >> x >> y >> a >> b;
        if(x < y) cout << find_sum(1, N, 1, x, y) << '\n';
        else cout << find_sum(1, N, 1, y, x) << '\n';
        change(1, N, 1, a, b);
        arr[a] = b;
    }

    return 0;
}