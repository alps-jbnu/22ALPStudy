#include <iostream>
using namespace std;

int num[10];
int main(void) {
    int A, B, C, res;
    cin >> A >> B >> C;
    res = A*B*C;
    while(res>0){
        num[res%10]++;
        res/=10;
    }
    for(int i = 0; i < 10; i++) cout << num[i] << '\n';
}