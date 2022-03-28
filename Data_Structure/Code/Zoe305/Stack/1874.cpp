#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, data, idx;
    vector<int> vec1;
    vector<char> vec2;
    stack<int> s;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> data;
        vec1.push_back(data);
    }
    
    for(int i = 1; i <= n; i++){
        s.push(i);
        vec2.push_back('+');
        
        while(!s.empty()){
            if(vec1[idx] == s.top()){
                s.pop();
                vec2.push_back('-');
                idx++;
            }
            else break;
        }
    }
    
    if(s.empty()){
        for(int i = 0; i < vec2.size(); i++){
            cout << vec2[i] << "\n";
        }
    }
    else cout << "NO" << "\n";
    
    return 0;

}