#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, v, a[201] = {};
  cin >> N;

  while(N--){
    int t;
    cin >> t;
    a[t+100]++;
  }


  cin >> v;
  cout << a[v+100];
}