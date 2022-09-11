#include <iostream>
using namespace std;

int dp[1001] = { 1, 1, 3 };

int f(int n)
{
    if (dp[n]) return dp[n];

    return dp[n] = (f(n - 1) + 2 * f(n - 2)) % 10007;
}

int main() {
    int n;

    cin >> n;
    cout << f(n) << endl;

    return 0;
}