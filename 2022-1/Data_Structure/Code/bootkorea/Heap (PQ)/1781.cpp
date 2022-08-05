#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 200000 + 1;

int N, result = 0;
vector<pii> vec;
priority_queue<int> pq;

bool comp(int a, int b) 
{
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vec.resize(N + 1);

    for(int i = 0; i < N; i++)
    {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());

    int idx = N;
    for (int i = N; i >= 1; i--)
    {
        for (; idx >= 1 && vec[idx].first == i; idx--)
        {
            pq.push(vec[idx].second);
        }

        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
    
    return 0;
}