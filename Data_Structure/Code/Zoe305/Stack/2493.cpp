#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int> > s;
    int n, height;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> height;

        while (!s.empty()) {
            if (height < s.top().second) {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }

        if (s.empty()) {
            cout << 0 << " ";
        }

        s.push(make_pair(i + 1, height));
    }

    return 0;

}