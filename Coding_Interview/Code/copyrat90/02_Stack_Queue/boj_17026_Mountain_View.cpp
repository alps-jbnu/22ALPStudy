// 풀던 낙서: https://imgur.com/a/8IXWsAH

#include <bits/stdc++.h>
using namespace std;

struct Pos {int x, y; };

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;  cin >> N;
    vector<Pos> A(N);
    for (auto& a : A)
        cin >> a.x >> a.y;
    
    // O(NlogN)
    sort(A.begin(), A.end(), [] (const Pos& a, const Pos& b) -> bool {
        if (a.y+a.x != b.y+b.x)
            return a.y+a.x < b.y+b.x;
        return a.y-a.x < b.y-b.x;
    });

    // O(N)
    stack<Pos> st;
    for (const auto& p : A)
    {
        while (!st.empty() && st.top().y+st.top().x==p.y+p.x)
            st.pop();

        assert(st.empty() || st.top().y+st.top().x < p.y+p.x);

        while (!st.empty() && st.top().y-st.top().x <= p.y-p.x)
        {
            st.pop();
            assert(st.empty() || st.top().y+st.top().x < p.y+p.x);
        }

        st.push(p);
    }

    cout << st.size();
}
