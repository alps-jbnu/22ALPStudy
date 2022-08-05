#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    // 각 종류별 의상 개수를 카운팅
    unordered_map<string, int> m;
    for (const auto& cl : clothes)
    {
        const auto& kind = cl[1];
        m[kind]++;
    }

    // (종류별 의상 개수 + 1) 을 누적곱.
    // +1 은 이번 종류를 안 입는 경우.
    int ans = 1;
    for (const auto& p : m)
    {
        int sel = p.second + 1;
        ans *= sel;
    }
    // 아무것도 안 입은 경우를 빼야 하니 -1
    return ans - 1;
}
