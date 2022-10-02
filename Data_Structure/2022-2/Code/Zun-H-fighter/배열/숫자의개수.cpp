#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char s[11];
	int A,B,C, num, cot[10]={0};
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	num=A*B*C;
	sprintf(s,"%d",num);
	for(int i=0; i<10; i++){
		cot[s[i]-48]++;
	}
	for(int i=0; i<10; i++){
		if(i==9)
			printf("%d", cot[i]);
		else
			printf("%d\n", cot[i]);
		}
	return 0;
}
