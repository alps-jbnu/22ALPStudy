#include <bits/stdc++.h>
using namespace std;

int na, nb, count, num;
vector<int> a, b;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> na >> nb;

    for (int i = 0; i < na; i++) {
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < nb; i++) {
        cin >> num;
        b.push_back(num);
    }
    sort(b.begin(), b.end());

    vector<int> result;

    for (auto nxt : a) {
        if (binary_search(b.begin(), b.end(), nxt)) continue;
        result.push_back(nxt);
    }

    cout << result.size() << "\n";
    for (auto nxt : result) cout << nxt << " ";
    return 0;
}