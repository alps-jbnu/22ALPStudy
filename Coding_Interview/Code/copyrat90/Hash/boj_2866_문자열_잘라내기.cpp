// 풀이: https://velog.io/@copyrat90/BOJ-2866

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    char board[1000][1001];

    int R, C;
    cin >> R >> C >> ws;
    for (int y = 0; y < R; ++y)
        cin.getline(board[y], sizeof board[y]);
    
    // 세로줄로 된 문자열
    vector<string> hori(C);
    // 아랫행부터 윗행까지 보면서 반복
    for (int y = R-1; y >= 0; --y)
    {
        unordered_set<string> s;
        for (int x = 0; x < C; ++x)
        {
            // 이전 행까지의 문자열 += 이번 행의 글자
            hori[x] += board[y][x];
            // 이번 행까지의 문자열 중복 체크
            s.insert(hori[x]);
        }

        // C개 열이 모두 unique 한 문자열이면, 중복이 없는 행이므로
        // 이번 행의 idx(y) 출력 후 종료
        if (s.size() == C)
        {
            cout << y;
            return 0;
        }
    }

    // 가장 처음에 주어지는 테이블에는 열을 읽어서 문자열을 만들 때,
    // 동일한 문자열이 존재하지 않는 입력만 주어진다.
    assert(false);
}
