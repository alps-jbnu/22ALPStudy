#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<int> A(N);
    for (int& a : A)
        cin >> a;
    
    ll ans = 0;
    // {키, 중복인원수}
    stack<pair<int,int>> st;
    for (int i=0;i<N;++i)
    {
        while (!st.empty())
        {
            // 직전보다 작은 키가 추가되는 경우
            if (st.top().first > A[i])
            {
                // 직전 1명과만 서로 볼 수 있음
                ++ans;
                break;
            }
            // 직전과 같은 키가 추가되는 경우
            else if (st.top().first == A[i])
            {
                // 기존 키 같은 인원 전부와 서로 볼 수 있음
                ans += st.top().second;
                // 그것보다 큰 인원이 존재하면, 그 1명과도 서로 볼 수 있음
                if (st.size() >= 2)
                    ans += 1;
                break;
            }
            // 직전보다 큰 키가 추가되는 경우
            else // st.top().first < A[i]
            {
                // 직전 키 인원들 전부 볼 수 있음
                ans += st.top().second;
                // 이제 직전 키 인원들은 더 이상 볼 수 있는 쌍이 없으므로, pop()
                st.pop();
                // 그 전 인원도 계속 살펴봄
                continue;
            }
        }
        
        // 이러면, st는 내림차순으로 유지됨
        assert(st.empty() || st.top().first >= A[i]);

        // 이번 키 추가
        if (st.empty() || st.top().first > A[i])
            st.push({A[i], 1});
        else // st.top().first == A[i]
            st.top().second++;
    }

    cout << ans;
}
