#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;  cin >> N;
    vector<int> A(N);
    for (int& a:A) cin>>a;

    sort(A.begin(),A.end());

    // 자기 자신을 어떻게 제외할까?
    // 다른 수 2개 중 0 이 들어간 개수에 따라 case work

    // 총 시간복잡도: O(N^2 logN)
    int ans = 0;
    for (int k=0;k<N;++k)
    {
        // 좋은 수 -> cur == A[i] + want <- 두 수
        const int cur = A[k];
        for (int i=0;i<N;++i)
        {
            if (i == k) continue;
            const int want = cur - A[i];
            // 못찾았으면 pass
            if (!binary_search(A.begin(),A.end(),want))
                continue;
            // 선택한 2개 중 0의 개수
            // i) 0개
            if (want != 0 && A[i] != 0)
            {
                // want 와 A[i] 가 같은 수인 경우, 같은 수가 2개 이상 있어야 함.
                if (want == A[i])
                {
                    auto p = equal_range(A.begin(),A.end(),want);
                    const int cnt = p.second-p.first;
                    if (cnt >= 2)
                    {
                        ++ans;
                        break;
                    }
                }
                else
                {
                    ++ans;
                    break;
                }
            }
            // ii) 2개
            if (want == 0 && A[i] == 0)
            {
                // 0이 3개 있어야 성립
                auto p = equal_range(A.begin(),A.end(),0);
                const int cnt = p.second-p.first;
                if (cnt >= 3)
                {
                    ++ans;
                    break;
                }
            }
            // iii) 1개
            else
            {
                // 좋은 수가 2개 이상 있어야 성립
                auto p = equal_range(A.begin(),A.end(),cur);
                const int cnt = p.second-p.first;
                if (cnt >= 2)
                {
                    ++ans;
                    break;
                }
            }
        }
    }

    cout<<ans;
}
