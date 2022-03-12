#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> m;
    // 모든 선수 이름 별 카운트 증가 (동명이인이면 카운트 2 이상)
    for (const auto& p : participant)
        m[p]++;

    // 완주한 선수 카운트 감소 (0 되는 순간 map에서 삭제)
    for (const auto& p : completion)
    {
        auto it = m.find(p);
        if (it != m.end())
            if (--it->second == 0)
                m.erase(it);
    }

    // 조건에 따라, map에 남은 (완주 못한) 인원은 반드시 1명.
    assert(m.size() == 1);
    string answer = m.begin()->first;
    return answer;
}
