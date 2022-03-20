#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
constexpr bool ndebug = false;
#define debugf(...) printf("[DEBUG] "); printf(__VA_ARGS__)
#else
constexpr bool ndebug = true;
#define debugf(...) ((void)0)
#endif

#define dbgout if constexpr (!ndebug) cout << "[DEBUG] "

using ll = long long;

constexpr ll gcd(ll a, ll b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

struct Rat
{
private:
    ll _numer, _denom;
    
public:
    Rat(ll numer = 0, ll denom = 1) : _numer(numer), _denom(denom)
    {
        ll gcdVal = gcd(denom, numer);
        _numer = numer / gcdVal;
        _denom = denom / gcdVal;
        dbgout << *this << " Generated.\n";
    }

    Rat operator + (const Rat& other) const
    {
        return Rat(_numer * other._denom + other._numer * _denom, _denom * other._denom);
    }

    Rat& operator += (const Rat& other)
    {
        _numer = _numer * other._denom + other._numer * _denom;
        _denom *= other._denom;
        ll gcdVal = gcd(_denom, _numer);
        _numer /= gcdVal;
        _denom /= gcdVal;
        return *this;
    }

    Rat operator * (const Rat& other) const
    {
        return Rat(_numer * other._numer, _denom * other._denom);
    }

    bool operator < (const Rat& other) const
    {
        const bool ret = _numer * other._denom < other._numer * _denom;
        dbgout << *this << " < " << other << " == " << ret << "\n";
        return ret;
    }

    friend ostream& operator << (ostream& os, const Rat& rat);
};

ostream& operator << (ostream& os, const Rat& rat)
{
    os << "Rat{" << rat._numer << "/" << rat._denom << "}";
    return os;
}

const static Rat half = Rat(1,2);

int main()
{
    if constexpr (ndebug)
        cin.tie(0)->sync_with_stdio(0);

    ll N, M;
    string king;
    cin >> N >> M >> king;

    unordered_map<string, ll> nameToId;
    nameToId[king] = 0;
    vector<ll> indegree(1);
    vector<vector<ll>> adjList(1);
    vector<Rat> rats(1, Rat(1));

    auto getNameId = [&indegree, &adjList, &nameToId, &rats] (const string& name) -> ll {
        const auto pib = nameToId.insert({name, nameToId.size()});
        if (pib.second)
        {
            adjList.push_back(vector<ll>());
            indegree.push_back(0);
            rats.push_back(Rat());
        }
        assert(adjList.size() == nameToId.size());
        assert(indegree.size() == nameToId.size());
        assert(rats.size() == nameToId.size());
        return pib.first->second;
    };

    for (int i=0;i<N;++i)
    {
        string child, parent1, parent2;
        cin >> child >> parent1 >> parent2;
        const ll c = getNameId(child);
        const ll p1 = getNameId(parent1);
        const ll p2 = getNameId(parent2);

        adjList[p1].push_back(c);
        adjList[p2].push_back(c);
        indegree[c] += 2;
    }

    // 혈통 계산은 의존성 있는 작업(반드시 조상부터 계산해야 함)
    // 따라서, 위상 정렬 필요.
    queue<ll> q;
    for (ll i=0; i<indegree.size(); ++i)
        if (indegree[i] == 0)
            q.push(i);

    // 위상 정렬
    while (!q.empty())
    {
        const ll cur = q.front();
        q.pop();
        for (ll adj : adjList[cur])
        {
            rats[adj] += half * rats[cur];
            if (--indegree[adj] == 0)
                q.push(adj);
        }
    }

    // 혈통 가까운 사람 찾기
    priority_queue<pair<Rat,string>> pq;
    for (ll i=0;i<M;++i)
    {
        string candi; cin >> candi;
        const ll c = getNameId(candi);
        pq.push({rats[c], candi});
    }
    cout << pq.top().second;
}
