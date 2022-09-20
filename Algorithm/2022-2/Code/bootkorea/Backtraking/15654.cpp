#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, arr[9] = { 0, };
bool visit[9];
vector<int> vec;

#define endl "\n"

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
}

void select(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visit[i] == true)
        {
            continue;
        }
        visit[i] = true;
        vec.push_back(arr[i]);
        select(cnt + 1);
        visit[i] = false;
        vec.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    select(0);

    return 0;
}