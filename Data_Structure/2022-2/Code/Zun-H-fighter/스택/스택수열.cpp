#include <iostream>
#include <stack>

using namespace std;

int arr[1000000];
char ch[2000000];

int main(){
	stack<int> s, s2;
	int N, n, i=1, idx=0;
	bool no=false;
	
	cin >> N;
	for(int j=0; j<N; j++)
		cin >>arr[j];
	for(int j=N-1; j>=0; j--){
		s.push(arr[j]);
	}
	while(!s.empty()){
		if(s2.empty()){
			s2.push(i);
			ch[idx]='+';
			idx++;
			i++;
		}
		else if(s2.top()<s.top()){
			while(s.top()>s2.top()){
				s2.push(i);
				ch[idx]='+';
				idx++;
				i++;
			}
		}
		else if(s2.top()>s.top()){
			no=true;
			break;
		}
		else if(s2.top()==s.top()){
			s2.pop();
			s.pop();
			ch[idx]='-';
			idx++;
		}
	}
	if(no==true)
		cout << "NO";
	else{
		for(int j=0; ch[j]; j++){
			cout << ch[j] << "\n";
		}
	}
	return 0;
}
