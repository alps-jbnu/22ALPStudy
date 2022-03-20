#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> q;
  int N;
  cin >> N;

  for(int i = 0; i < N; i++){
      q.push(i);
  }

  while(q.size() > 1){
      q.pop();
      q.push(q.front());
      q.pop();
  }
  
  cout << q.front();
  
  return 0;
}