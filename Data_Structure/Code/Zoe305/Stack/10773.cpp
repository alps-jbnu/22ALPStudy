#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, sum = 0;
    stack<int> s;

    cin >> k;
    while (k--) {
        int x;
        cin >> x;
        if (x == 0) {
            sum -= s.top();
            s.pop();
        }
        else {
            s.push(x);
            sum += x;
        }
    }

    cout << sum;
    
    return 0;
  
}