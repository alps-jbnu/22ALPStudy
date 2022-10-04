#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> s;
	int K, n, sum=0;
	cin >> K;
	while(K--){
		cin >> n;
		if(!n)
			s.pop();
		else
			s.push(n);
	}
	while(!s.empty()){
		sum+=s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}
