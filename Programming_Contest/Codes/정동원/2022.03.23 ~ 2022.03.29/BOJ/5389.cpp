#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void solve()
{
    long long n;
    cin >> n;

    long long a, b, r, x;
    long long start = sqrt(n);
    for (int i = start; i > 0 ; i--)
    {
        if(n % i == 0)
        {
            a = i;
            b = n / i;

            if(a * b != n) continue;

            r = (a + b) / 2;
            x = (b - a) / 2;

            if(r < 0 || x < 0 || r * r - x * x != n) continue;

            cout << x << " " << r << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }
}