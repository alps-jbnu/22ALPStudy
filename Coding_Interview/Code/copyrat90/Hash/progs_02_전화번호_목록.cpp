#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
    // s[idx]: 전화번호 길이 idx인 모든 전화번호를 저장
    unordered_set<string> s[21];
    // 모든 전화번호 순회하며, 전화번호 길이에 해당하는 set에 전화번호 저장
    for (const auto& p : phone_book)
        s[p.size()].insert(p);

    // n = 배열 길이, k = 전화번호 길이
    // 총 시간복잡도: O(nk)

    // 모든 전화번호 다시 순회
    for (const auto& p : phone_book)
    {
        // 이번 전화번호의 모든 가능한 접두사를 substr() 으로 만들고,
        // 그 길이에 해당하는 set에 접두사가 들어있는지 확인: O(k)
        for (int i = 1; i < p.size(); ++i)
            if (s[i].find(p.substr(0, i)) != s[i].end())
                return false;
    }

    return true;
}
