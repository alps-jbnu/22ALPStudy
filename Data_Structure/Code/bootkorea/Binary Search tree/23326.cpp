#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
const int MAX = 500000 + 1;

int N, Q;
int arr[MAX];
set<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int now = 1;

    cin >> N >> Q;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;

        if (x == 1) st.insert(i);
    }

    while (Q--)
    {
        int cnt;
        cin >> cnt;

        if (cnt == 1)
        {
            int i;
            cin >> i;

            if (!arr[i])
            {
                arr[i] = 1;
                st.erase(i);
            }
            else
            {
                arr[i] = 0;
                st.erase(i);
            }
        }
        else if (cnt == 2)
        {
            int x;
            cin >> x;
            
            now += (x %= N);

            if (now > N) now -= N;
        }
        else
        {
            if (st.empty()) cout << "-1" << "\n";
            else
            {
                auto num = st.lower_bound(now);

                if (num != st.end()) cout << *num - now << "\n";
                else
                {
                    cout << N - now + *st.begin() << "\n";
                }
            }
        }
    }
    

    return 0;
}