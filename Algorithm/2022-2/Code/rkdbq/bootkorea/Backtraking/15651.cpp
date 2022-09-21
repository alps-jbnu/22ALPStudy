#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool Visited[9];
vector<int> vec;

void Solve(int index, int cnt) {
    if (cnt == M)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";

        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {

        vec.push_back(i + 1);
        Solve(i, cnt + 1);
        vec.pop_back();

    }
}


int main() {
    cin >> N >> M;

    Solve(0, 0);

    return 0;
}