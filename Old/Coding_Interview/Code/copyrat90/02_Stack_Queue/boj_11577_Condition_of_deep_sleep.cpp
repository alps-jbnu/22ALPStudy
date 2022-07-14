#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    bitset<100'000> S(N);
    for (int i=0;i<N;++i)
    {
        int tmp; cin >> tmp;
        S[i] = (tmp == 1);
    }
    
    // 핵심 아이디어: 제일 왼쪽 전구가 켜져 있다면, 반드시 제일 왼쪽부터 K개는 꺼야 한다.
    // 고로, 왼쪽부터 1개씩 보면서 이번 걸 꺼야하면 연속된 K개를 끄는 그리디한 풀이가 떠오른다.

    // 하지만 N개 전구를 하나씩 보며 매번 K개를 끄면, O(NK)로 시간 초과일 것이다.
    // 매번 끄는 대신에, i번에 끈다면, i+K-1까지 반전되었다는 상태를 큐에 저장하자.

    // i번째 반복에선 우선 큐에서 i번 이전 idx를 전부 pop() 하고,
    // 큐에 들어있는 원소의 개수가 짝수이면 반전의 반전이므로 현재 상태 그대로,
    // 홀수이면 반전이므로 현재 상태를 toggle한 다음 끌지 말지를 판단하자.

    // 이러면 i번째 원소는 최대 2번 toggle 되므로, O(N)만에 해결 가능.

    int ans = 0;
    queue<int> q;
    // 새로 끌 전구 찾는 루프
    for (int i=0;i<=N-K;++i)
    {
        while (!q.empty() && q.front() < i)
            q.pop();
        
        if (q.size() % 2 == 1)
            S.flip(i);
        
        if (S.test(i))
        {
            S.flip(i);
            ++ans;
            q.push(i+K-1);
        }
    }

    // 큐에 남은 toggle된 전구들 후처리
    // (새로 끌 전구 찾기 X, 기존에 꺼진것만 후처리)
    for (int i=N-K+1;i<N;++i)
    {
        while (!q.empty() && q.front() < i)
            q.pop();
        
        if (q.size() % 2 == 1)
            S.flip(i);
    }

    if (S.any())
        cout << "Insomnia";
    else
        cout << ans;
}
