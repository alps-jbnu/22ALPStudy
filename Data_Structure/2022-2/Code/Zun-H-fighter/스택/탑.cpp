#include <iostream>
#include <stack>
using namespace std;

int arr[500001];
int ops[500001];
int main(){
	stack<int> S, is;
	int N, plag;
	
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> arr[i];
	for(int i=1; i<=N; i++){
		if(i==1){
			ops[i]=0;
			S.push(arr[i]);
			is.push(i);
		}
		else{
			plag=0;
			while(!S.empty()){
				if(S.top()>=arr[i]){
					ops[i]=is.top();
					S.push(arr[i]);
					is.push(i);
					plag=1;
					break;
				}
				else if(S.top()<arr[i]){
					S.pop();
					is.pop();
				}
			}
			if(plag==0){
				ops[i]=0;
				S.push(arr[i]);
				is.push(i);
			}
		}
		cout <<ops[i]<<" ";
	}	
	return 0;	
}
