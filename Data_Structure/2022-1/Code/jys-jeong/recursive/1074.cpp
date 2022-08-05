#include<bits/stdc++.h>
using namespace std;


int a = 0;
int  r, c;
void hansu(int x, int y,int size) {


	if (x == r && y == c) {
		cout << a;
		exit(0);
	}
	if (r <= x + size - 1 && c <= y + size - 1) {

	}
	else {
		a += size * size;
		return;
	}

	hansu(x, y, size / 2);
	hansu(x, y + size / 2, size / 2);
	hansu(x+size/2, y, size / 2);
	hansu(x+size/2,y+size/2 , size / 2);


}


int main() {
	int n;
	cin >> n >> r >> c;
	
	hansu(0,0,pow(2,n));
 }