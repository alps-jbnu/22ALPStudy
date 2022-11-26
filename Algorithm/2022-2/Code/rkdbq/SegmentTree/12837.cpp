#define MX_N 1000001
#define MX_Q 100001

#include <iostream>
using namespace std;

int N, Q;
int x, p, q;
long long sum[MX_N * 4];

void update(int st, int en, int node, int p, int x)
{
    if (st > p || en < p)
        return;
    sum[node] += x;
    if (st == en)
        return;
    int mid{(st + en) / 2};
    update(st, mid, node * 2, p, x);
    update(mid + 1, en, node * 2 + 1, p, x);
}

long long find(int st, int en, int node, int p, int q)
{
    if (st > q || en < p)
        return 0;
    if (st >= p && en <= q)
        return sum[node];
    int mid{(st + en) / 2};
    return find(st, mid, node * 2, p, q) + find(mid + 1, en, node * 2 + 1, p, q);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i{}; i < Q; i++)
    {
        int query_num;
        cin >> query_num;
        if (query_num == 1)
        {
            cin >> p >> x;
            update(1, N, 1, p, x);
        }
        else if (query_num == 2)
        {
            cin >> p >> q;
            cout << find(1, N, 1, p, q) << '\n';
        }
    }

    return 0;
}