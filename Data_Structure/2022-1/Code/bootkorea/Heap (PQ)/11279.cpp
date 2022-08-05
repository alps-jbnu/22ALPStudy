#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    priority_queue<int> pq;
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        
        if(x == 0 && pq.empty())
        {
            cout << "0" << "\n";
        }
        else if(x == 0)
        {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}
