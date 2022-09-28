#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool visit[9];
vector<int> vec;

void dfs(int index, int cnt) {
    if (cnt == M)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";

        }
        cout << endl;
        return;
    }

    for (int i = index; i < N; i++) {
        if (visit[i] == true)
        {
            continue;
        }
        visit[i] = true;
        vec.push_back(i + 1);
        dfs(i, cnt + 1);
        visit[i] = false;
        vec.pop_back();

    }
}


int main() {
    cin >> N >> M;

    dfs(0, 0);

    return 0;
}