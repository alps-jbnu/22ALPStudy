#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,int> S, E, Q;
    scanf("%d:%d %d:%d %d:%d", &S.first, &S.second, &E.first, &E.second, &Q.first, &Q.second);
    
    int ans = 0;
    unordered_set<string> ent;
    string raw;
    while (getline(cin, raw))
    {
        istringstream iss(raw);
        pair<int,int> time;
        char _;
        string userId;
        iss >> time.first >> _ >> time.second >> userId;
        // 정시 입장한 사람 명단 저장
        if (time <= S)
        {
            ent.insert(userId);
        }
        // 정시 퇴장한 사람이면
        else if (E <= time && time <= Q)
        {
            // 입장한 사람 명단에 있는지 체크하고, 있으면 답 +1
            // 이 때, 명단에서 삭제해 중복 +1 방지
            if (ent.find(userId) != ent.end())
                ++ans, ent.erase(userId);
        }
    }
    cout << ans;
}
