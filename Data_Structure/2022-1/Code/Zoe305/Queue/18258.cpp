#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, data;
  queue<int> q; string str;
  cin >> n;

  for(int i = 0; i < n; i++){
      cin >> str;

      if(str == "push") {
          cin >> data;
          q.push(data);
      }
      else if(str == "pop") {
          if (q.size() == 0) cout << "-1\n";
          else {
              data = q.front();
              q.pop();
              cout << data << "\n";
          }
      }
      else if(str == "size") cout << q.size() << "\n";
      else if(str == "empty") cout << q.empty() << "\n";
      else if(str == "front"){
          if(q.size() == 0) cout << "-1\n";
          else cout << q.front() << "\n";
      }
      else if(str == "back"){
          if(q.size() == 0) cout << "-1\n";
          else cout << q.back() << "\n";
      }
  }
  
  return 0;
}