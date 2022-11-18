#include <iostream>
using namespace std;

int num;
int paper[2200][2200];
int cnt[3]; 


bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[x][y] != paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}
void recur(int x, int y, int z)
{
    if (check(x, y, z)) {
        cnt[paper[x][y] + 1] += 1;
        return;
    }
    int n = z / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recur(x + i * n, y + j * n, n);
        }
    }
}


int main(void) {
    cin >> num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> paper[i][j];
        }
    }
    recur(0, 0, num);
    for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
}
