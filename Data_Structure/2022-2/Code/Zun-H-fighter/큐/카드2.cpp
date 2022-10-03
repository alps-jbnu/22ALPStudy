#include <iostream>

using namespace std;

int arr[5000000];
int head=0, tail=0;
long long tail_size=0;

int main(){
	int N, plag=0;
	cin >> N;
	for(int i=1; i<=N; i++){
		arr[tail++]=i;
		tail_size++;
	}
	while(!(tail_size-head==1)){
		head++;
		arr[tail++]=arr[head++];
		tail_size++;
		if(tail==5000001){
			tail=0;
		}
	}
	cout <<arr[head];
	return 0;
}
