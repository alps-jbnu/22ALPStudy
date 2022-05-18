#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N;

void func(int x, int y, int n)
{
    if (n == 1)
    {
        cout << x << ' ' << y << "\n";
        return;
    }
    else
    {
        func(x, 6 - x - y, n - 1);
        cout << x << ' ' << y << "\n";
        func(6 - x - y, y, n - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << (1 << N) - 1 << "\n";
    func(1, 3, N);

    return 0;
}