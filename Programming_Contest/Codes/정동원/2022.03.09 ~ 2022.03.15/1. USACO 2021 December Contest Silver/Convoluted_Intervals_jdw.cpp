#include <iostream>
using namespace std;

int n, m, a, b;
long long begin_pos[200001];
long long end_pos[200001];
long long sum_begin[400001];
long long sum_end[400001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    //* 시작점과 끝점 개수 카운트
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        begin_pos[a]++;
        end_pos[b]++;
    }

    //* (ai, bi)와 (aj, bj) 선택
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            //* i + j 에서 시작하는 경우의 수(ai에서 시작하는 개수 * aj에서 시작하는 개수)를 더함
            sum_begin[i + j] += begin_pos[i] * begin_pos[j];
            //* 끝나는 경우의 수(bi에서 끝나는 개수 * bj에서 끝나는 개수)를 더함
            sum_end[i + j] += end_pos[i] * end_pos[j];
        }
    }
    
    long long k = 0;
    for (int p = 0; p <= 2 * m; p++)
    {
        //* 현재 p에서 시작하는 경우의 수는 더하고 끝나는 경우의 수는 뺌
        //* 빼는건 이전 자리에 저장되어 있으므로 -1 위치에 있는걸 뺌
        k += sum_begin[p] - sum_end[p - 1];
        cout << k << "\n";
    }
    
    return 0;
}
