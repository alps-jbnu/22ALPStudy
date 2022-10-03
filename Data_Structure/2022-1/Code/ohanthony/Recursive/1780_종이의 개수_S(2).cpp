#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int arr[2200][2200];
int a, b, c;
int N;

bool check(int x, int y, int n){ // 종이가 모두 같은 수로 되어있는지 여부 판단
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++) {
            // 하나라도 다르면 false 값 return
            if(arr[x][y] != arr[i][j]) return false;
        }
    }
    return true;
}


void func(int row, int col, int N){
    if(check(row, col, N)){
        if(arr[row][col] == -1) a++;
        else if(arr[row][col] == 0) b++;
        else c++;

        return;
    }

    int temp = N/3; // 9등분 하므로 다음과 같은 식 도출
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            func(row + temp*i, col + temp*j, temp);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    func(0, 0, N);

    cout << a << '\n' << b << '\n' << c;
}
