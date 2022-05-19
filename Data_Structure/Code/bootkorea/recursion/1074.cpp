#include <iostream>
#define endl "\n"
using namespace std;

int N, r, c, result = 0;

void Z(int x, int y, int n)
{
    if (x == r && y == c)
    {
        cout << result << "\n";
        return;
    }

    if ((r >= x && r < x + n) && (c >= y && c < y + n))
    {
        Z(x, y, n / 2);
        Z(x, y + n / 2, n / 2);
        Z(x + n / 2, y, n / 2);
        Z(x + n / 2, y + n / 2, n / 2);
    }
    else result += n * n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    Z(0, 0, (1 << N));

    return 0;
}