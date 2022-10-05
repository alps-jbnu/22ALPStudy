#include <iostream>
#include <deque>

using namespace std;
 
int a[51], a_n[51];

int main(){
	deque<int> d;
	int N, m, j=0, cnt=0;
	
	cin >> N >> m;
	for(int i=1; i<=N; i++)
		d.push_back(i);
	for(int i=0; i<m; i++){
		cin >> a[i];
		a_n[i]=a[i];
	}
	while(a[m-1]){
		if(d.size()-a_n[j]+2>a_n[j]-1){
			while(a[j]!=d.front()){
				d.push_back(d.front());
				d.pop_front();
				cnt++;
				for(int i=j+1; i<m; i++){
					a_n[i]--;
					if(a_n[i]==0)
						a_n[i]=d.size();
				}
			}
		}
		else{
			while(a[j]!=d.front()){
				d.push_front(d.back());
				d.pop_back();
				cnt++;
				for(int i=j+1; i<m; i++){
					a_n[i]++;
					if(a_n[i]==d.size()+1)
						a_n[i]=1;
				}
			}
		}
		d.pop_front();
		a[j]=0;
		j++; 
		for(int i=j; i<m; i++){
			a_n[i]--;	
			if(a_n[i]==0)
				a_n[i]=d.size();
		}
	}
	cout <<cnt;
	return 0;
}
