#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define ll long long

int Priority(char p)
{
	switch(p){
		case '(': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default: break;
	}
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	string s, result = "";
	cin >> s;

	stack<char> oper;
	for(auto c : s){
		if(c == '(') oper.push(c);
		else if(c == ')'){
			while(oper.top() != '('){
				result += oper.top();
				oper.pop();
			}
			oper.pop();
		}
		else if(c == '+' || c == '-' || c == '*' || c == '/'){
			while(!oper.empty() && Priority(oper.top()) >= Priority(c)){
				result += oper.top();
				oper.pop();
			}
			oper.push(c);
		}
		else result += c; // 연산자 아닌 경우 result에 값 더해줌
	}

	while(!oper.empty()){
		result += oper.top();
		oper.pop();
	}
	cout << result;
	return 0;
}
