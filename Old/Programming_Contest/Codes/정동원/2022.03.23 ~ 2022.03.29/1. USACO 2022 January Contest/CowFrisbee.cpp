//! 45m
#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    long long sum = 0;

    long long num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        while(!s.empty() && s.top().second < num)
        {
            sum += i - s.top().first + 1;
            // cout << "(" << s.top().first <<", " << i << ")\n";
            s.pop();
        }
        if(!s.empty()) sum += i - s.top().first + 1;
        s.push({i, num});
    }

    cout << sum << "\n";
}