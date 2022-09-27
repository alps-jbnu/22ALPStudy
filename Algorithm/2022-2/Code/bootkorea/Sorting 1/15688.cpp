#include <bits/stdc++.h>
const int MAX = 2000000 + 1;
const int HALF = MAX / 2;
using namespace std;

int N, t;
vector<int> numcnt(MAX + 2);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        cin >> t;
        numcnt[t + HALF]++;
    }

    for (int i = 0; i <= MAX; i++)
    {
        while (numcnt[i]--) cout << i - HALF << '\n';
    }
}