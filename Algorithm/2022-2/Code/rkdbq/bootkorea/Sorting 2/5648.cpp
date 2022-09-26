#include <bits/stdc++.h>
const int MAX = 100000 + 1;
using namespace std;

int N;
string str;
vector<long long> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        reverse(str.begin(), str.end());

        vec.push_back(stoll(str));
    }
    sort(vec.begin(), vec.end());

    int cnt = vec.size();
    for (int i = 0; i < cnt; i++)
    {
        cout << vec[i] << "\n";
    }

    return 0;
}