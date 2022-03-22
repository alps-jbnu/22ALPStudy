#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> v(n);
    vector<int> nge(n);
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    s.push(0);
    for (int i = 1; i < n; i++) {
        if (s.empty()) s.push(i);
        while (!s.empty() && v[s.top()] < v[i]) {
            nge[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    
    while (!s.empty()) {
        nge[s.top()] = -1;
        s.pop();
    }
    
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    
    return 0;

}