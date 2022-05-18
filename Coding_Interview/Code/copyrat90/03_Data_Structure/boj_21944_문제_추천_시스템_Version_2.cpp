#include <bits/stdc++.h>
using namespace std;

struct Problem
{
    int id, level, group;
    bool operator<(const Problem& other) const
    {
        if (level != other.level)
            return level < other.level;
        return id < other.id;
    }
};

class RecList
{
private:
    set<Problem> whole_set, group_set[101], level_set[101];
    map<int, Problem> id_to_problem;

public:
    void add(int id, int level, int group)
    {
        Problem p{id, level, group};
        whole_set.insert(p);
        group_set[group].insert(p);
        level_set[level].insert(p);
        id_to_problem[id] = p;
    }

    void solve(int id)
    {
        const auto& p = id_to_problem[id];
        whole_set.erase(p);
        group_set[p.group].erase(p);
        level_set[p.level].erase(p);
    }

    int rec1(int group, bool hard) const
    {
        return hard ? group_set[group].rbegin()->id : group_set[group].begin()->id;
    }

    int rec2(bool hard) const
    {
        return hard ? whole_set.rbegin()->id : whole_set.begin()->id;
    }

    int rec3(bool hard, int level) const
    {
        const Problem* p = nullptr;
        if (hard)
        {
            for (int l = level - 1; l >= 1; --l)
                if (!level_set[l].empty())
                {
                    p = &*level_set[l].rbegin();
                    break;
                }
        }
        else
        {
            for (int l = level; l <= 100; ++l)
                if (!level_set[l].empty())
                {
                    p = &*level_set[l].begin();
                    break;
                }
        }

        return p ? p->id : -1;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    RecList recList;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int P, L, G;
        cin >> P >> L >> G;
        recList.add(P, L, G);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        string op;
        int a, b, c;
        cin >> op >> a;
        if (op == "recommend")
        {
            cin >> b;
            cout << recList.rec1(a, b == 1) << '\n';
        }
        else if (op == "recommend2")
        {
            cout << recList.rec2(a == 1) << '\n';
        }
        else if (op == "recommend3")
        {
            cin >> b;
            cout << recList.rec3(a == -1, b) << '\n';
        }
        else if (op == "add")
        {
            cin >> b >> c;
            recList.add(a, b, c);
        }
        else // op == "solved"
        {
            recList.solve(a);
        }
    }
}
