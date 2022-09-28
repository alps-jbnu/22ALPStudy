#include <bits/stdc++.h>
const int MAX = 50 + 1;
using namespace std;

int N;
string str[MAX];

int comp(const string& x, const string& y)
{
    int size_x = x.length(), size_y = y.length();
    if (size_x != size_y) return size_x < size_y;

    int sum_x = 0, sum_y = 0;
    for (int i = 0; i < size_x; i++)
    {
        if ('0' <= x[i] && x[i] <= '9') sum_x += x[i] - '0';
        if ('0' <= y[i] && y[i] <= '9') sum_y += y[i] - '0';
    }
    if (sum_x != sum_y) return sum_x < sum_y;

    return x < y;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }
    sort(str, str + N, comp);

    for (int i = 0; i < N; i++)
    {
        cout << str[i] << "\n";
    }
    return 0;
}