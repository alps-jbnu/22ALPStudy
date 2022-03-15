#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int sum=0;
    map<string,int> m;
    string s;
    while (getline(cin, s))
        m[s]++, sum++;

    cout << fixed;
    cout.precision(4);
    for (const auto& p : m)
        cout << p.first << ' ' << (double)p.second / sum * 100 << '\n';
}
