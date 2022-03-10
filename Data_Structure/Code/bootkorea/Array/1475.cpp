#include<stdio.h>

int main() 
{
	int a, b, c, num, arr[10] = { 0 }, result = 0;
	scanf("%d %d %d", &a, &b, &c);
	result = a * b * c;

	while (result > 0) {
		num = result % 10;
		arr[num]++;
		result = result / 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
}