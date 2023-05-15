#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// µ¹ °ÔÀÓ
int main(void) {
	int n;
	scanf("%d", &n);

	if ((n % 2) == 0) //Â¦¼ö
		printf("CY"); 
	else //È¦¼ö
		printf("SK");
	return 0;
}