#include <stdio.h>

int main(void) {
	int cnt, num[100] = { 0, 1, 2, 4, 0 }, number;
	scanf("%d", &cnt);

	for (int i = 1; i <= cnt; i++) {
		scanf("%d", &number);
		for (int j = 4; j <= number; j++) {
			num[j] = num[j - 1] + num[j - 2] + num[j - 3];
		}
		printf("%d\n", num[number]);
	}
	return 0;
}