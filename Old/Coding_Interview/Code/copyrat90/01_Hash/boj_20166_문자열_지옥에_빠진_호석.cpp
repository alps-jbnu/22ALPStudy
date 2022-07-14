#include <bits/stdc++.h>
using namespace std;

constexpr pair<int,int> udlrdiag[8] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

int N,M,K;

// 8방향^5글자 = 2^15 = 32,768 회
void bfs(int y, int x, unordered_map<string,int>& likes, const char (* const board)[11])
{
    queue<pair<pair<int,int>,string>> q;
    q.push({pair<int,int>{y, x}, string(1,board[y][x])});
    // 신이 좋아하는 문자열이 1글자 문자열인 경우는 우선 처리
    auto like = likes.find(string(1,board[y][x]));
    if (like != likes.end())
        ++like->second;

    // BFS
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (const auto& dir : udlrdiag)
        {
            pair<pair<int,int>,string> candi
            {pair<int,int>{cur.first.first+dir.first, cur.first.second+dir.second}, cur.second };

            // 환형 이동
            while (candi.first.first < 0)
                candi.first.first += N;
            while (candi.first.second < 0)
                candi.first.second += M;
            while (candi.first.first >= N)
                candi.first.first -= N;
            while (candi.first.second >= M)
                candi.first.second -= M;
            
            // 새로운 위치의 문자를 append
            candi.second.append(1,board[candi.first.first][candi.first.second]);

            // printf("[DEBUG] candi={ %d, %d, %s }\n", candi.first.first, candi.first.second, candi.second.c_str());

            auto like = likes.find(candi.second);
            if (like != likes.end())
                ++like->second;
            if (candi.second.size() <= 4)
                q.push(candi);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    char board[10][11];

    cin>>N>>M>>K>>ws;
    for (int y=0;y<N;++y)
        cin.getline(board[y], sizeof board[y]);


    // key: 좋아하는 문자열, val: 발견된 개수
    unordered_map<string,int> likes;
    // 신이 좋아하는 문자열은 중복될 수도 있으므로,
    // 문자열을 순서대로 따로 저장해뒀다가 나중에 순서대로 조회
    vector<string> inputStrs(K);
    for (int i=0;i<K;++i)
    {
        cin >> inputStrs[i];
        likes.insert({inputStrs[i], 0});
    }

    // 보드판 최대 크기 10x10 = bfs() 100번까지 호출됨.
    for (int y=0;y<N;++y)
        for (int x=0;x<M;++x)
            bfs(y, x, likes, board);

    // 신이 좋아하는 문자열은 중복될 수도 있으므로,
    // 문자열을 순서대로 따로 저장해뒀다가 순서대로 조회
    for (const auto& s : inputStrs)
        cout << likes[s] << '\n'; 
}
