#include <string>
#include <vector>
#include <list>
#include <array>

using namespace std;

void nextIt(list<pair<int,int>>& l, list<pair<int,int>>::iterator& it)
{
    if (it == l.end())
        it = l.begin();
    if (++it == l.end())
        it = l.begin();
}

bool hasMoreUrgent(const array<int,10>& priCnts, int p)
{
    for (int i=p+1;i<=9;++i)
        if (priCnts[i] > 0)
            return true;
    return false;
}

int solution(vector<int> priorities, int location) {
    const int N=priorities.size();
    vector<int> ans(N);
    int order = 1;
    
    array<int,10> priCnts = {0,};
    for (int p : priorities)
        priCnts[p]++;
    
    // {idx, priority}
    list<pair<int,int>> pL;
    for (int i=0;i<N;++i)
        pL.push_back({i, priorities[i]});
    
    for (auto it = pL.begin(); !pL.empty();)
    {
        if (hasMoreUrgent(priCnts, it->second))
        {
            nextIt(pL, it);
            continue;
        }
        ans[it->first] = order++;
        priCnts[it->second]--;
        it = pL.erase(it);
        if (it == pL.end())
            it = pL.begin();
    }
    
    return ans[location];
}
