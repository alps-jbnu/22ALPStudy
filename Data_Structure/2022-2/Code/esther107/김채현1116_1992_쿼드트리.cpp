#include <iostream>
using namespace std;

int quadTree[66][66];
int num;

void recur(int x, int y, int n) {
	if(n == 1) {
		cout << quadTree[x][y];
		return;
	}
	bool zero = true;
	bool one = true;
	for(int i = x; i < x+n; i++) {
		for(int j = y; j < y + n; j++) {
			if(quadTree[i][j])
				zero = false;
			else
				one = false;
		}
	}
	if(zero) cout << 0;
	else if(one) cout << 1; 
	else {
		cout << "(";
		
		recur(x, y, n/2);
		
		recur(x, y+n/2, n/2);
		
		recur(x+n/2, y, n/2);
		
		recur(x+n/2, y+n/2, n/2);
		
		cout << ")";
	}
}

int main(void)
{	
	cin >> num;
	for(int i = 0; i < num; i++) {
		string str;
		cin >> str;
		for(int j = 0; j < num; j++) {
			quadTree[i][j] = str[j] - '0';
		}
	}
	 
	recur(0,0,num);
	return 0;
}
