#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
constexpr bool ndebug = false;
#else
constexpr bool ndebug = true;
#endif

#define debugf(...) if constexpr (!ndebug) { printf("[DEBUG] "); printf(__VA_ARGS__); }

int main()
{
    if constexpr (ndebug)
        cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<uint8_t> A(N);
    for (int i=0;i<N;++i)
    {
        char ch; cin >> ch;
        A[i] = ch-'0';
    }

    bitset<500000> del;
    // {idx, digit}
    stack<pair<int,uint8_t>> st;
    for (int i=0;i<N;++i)
    {
        while (!st.empty() && st.top().second < A[i])
        {
            debugf("Popped {%d, %d}\n", st.top().first, st.top().second);
            del[st.top().first]=true;
            st.pop();
            if (--K == 0)
                goto END;
        }
        st.push({i, A[i]});
    }
    while (!st.empty())
    {
        debugf("Popped {%d, %d}\n", st.top().first, st.top().second);
        del[st.top().first]=true;
        st.pop();
        if (--K == 0)
            goto END;
    }
END:
    assert(K == 0);
    for (int i=0;i<N;++i)
        if (!del[i])
            cout<<(int)A[i];
}
