#include <iostream>
#include <deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> dq;
    int m, n, cnt = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) dq.push_back(i);

    while (m--)
    {
        int idx, num;
        cin >> num;
        for (int i = 0; i < n; i++)
        {
            if (dq[i] == num)
            {
                idx = i;
                break;
            }
        }
        if (idx < dq.size() / 2 + 1)
        {
            for (int i = 0; i < dq.size(); i++)
            {
                if (dq.front() == num)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else
        {
            for (int i = 0; i < dq.size(); i++)
            {
                if (dq.front() == num)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}