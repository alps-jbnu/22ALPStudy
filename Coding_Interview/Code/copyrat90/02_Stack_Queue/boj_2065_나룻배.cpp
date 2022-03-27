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

    int M, t, N;
    cin>>M>>t>>N;

    vector<int> ans(N);

    // {time, idx}
    struct TimeIdx { int time, idx; bool operator < (const TimeIdx& other) { return time < other.time; } };
    vector<TimeIdx> left, right;
    left.reserve(N), right.reserve(N);
    int curTime = 0;
    bool boatOnLeft = true;
    for (int i=0;i<N;++i)
    {
        int srcTime;
        string srcPos;
        cin >> srcTime >> srcPos;
        if (srcPos == "left")
            left.push_back({srcTime, i});
        else
            right.push_back({srcTime, i});
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    queue<TimeIdx> leftQ, rightQ;
    for (auto& p : left)
        leftQ.push(p);
    for (auto& p : right)
        rightQ.push(p);

    while (!leftQ.empty() || !rightQ.empty())
    {
        // A. 이번 출발 시간 및 위치 지정

        // 1. 왼쪽에 올 손님 다 온 경우
        if (leftQ.empty())
        {
            debugf("case 1\n");
            curTime = (boatOnLeft ? t+max(rightQ.front().time, curTime) : max(rightQ.front().time, curTime));
            boatOnLeft=false;
        }
        // 2. 오른쪽에 올 손님 다 온 경우
        else if (rightQ.empty())
        {
            debugf("case 2\n");
            curTime = (boatOnLeft ? max(leftQ.front().time, curTime) : t+max(leftQ.front().time, curTime));
            boatOnLeft=true;
        }
        // 3. 배가 왼쪽에 있는데, 이미 왼쪽에 손님이 대기중
        else if (boatOnLeft && curTime >= leftQ.front().time)
        {
            debugf("case 3\n");
        }
        // 4. 배가 오른쪽에 있는데, 이미 오른쪽에 손님이 대기중
        else if (!boatOnLeft && curTime >= rightQ.front().time)
        {
            debugf("case 4\n");
        }
        // 5. 배가 대기하던 중(0초 대기 포함), 손님이 양쪽 정박장에 동시 도착
        else if (leftQ.front().time == rightQ.front().time)
        {
            debugf("case 5\n");
            curTime = (boatOnLeft ? leftQ : rightQ).front().time;
        }
        // 6. 배가 대기하던 중(0초 대기 포함), 왼쪽에 손님이 먼저 도착
        else if (leftQ.front().time < rightQ.front().time)
        {
            debugf("case 6\n");
            curTime = (boatOnLeft ? max(leftQ.front().time, curTime) : t+max(leftQ.front().time, curTime));
            boatOnLeft=true;
        }
        // 7. 배가 대기하던 중(0초 대기 포함), 오른쪽에 손님이 먼저 도착
        else if (leftQ.front().time > rightQ.front().time)
        {
            debugf("case 7\n");
            curTime = (boatOnLeft ? t+max(rightQ.front().time, curTime) : max(rightQ.front().time, curTime));
            boatOnLeft=false;
        }
        else // 그 외의 경우는 존재하지 않는다.
        {
            debugf("assert failed case\n");
            assert(false);
        }


        // B. 해당 시간 이전부터 대기 중인 손님 M명 태우고 출발 & 반대편 이동 처리
        auto& q = (boatOnLeft ? leftQ : rightQ);
        int mCnt = 0;
        while (mCnt++ < M && !q.empty() && q.front().time <= curTime)
        {
            ans[q.front().idx]=curTime+t;
            q.pop();
        }
        curTime+=t;
        boatOnLeft = !boatOnLeft;

        debugf("leftQ.size()==%lld / rightQ.size()==%lld\n",leftQ.size(), rightQ.size());
        debugf("boatOnLeft==%d\n", (boatOnLeft ? 1 : 0));
        debugf("curTime==%d\n", curTime);
    }

    for (int a : ans)
        cout << a << '\n';
}
