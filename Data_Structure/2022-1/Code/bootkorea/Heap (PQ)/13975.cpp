#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

int T, K;
ll result;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--)
    {
        result = 0;
        while (!pq.empty())
        {
            pq.pop();
        }
        
        cin >> K;
        for (int i = 0; i < K; i++)
        {
            int x; cin >> x;
            pq.push(x);
        }

        while (pq.size() > 1)
        {
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();

            result += (x + y);
            pq.push(x + y);
        }
        cout << result << "\n";
    }

    return 0;
}	