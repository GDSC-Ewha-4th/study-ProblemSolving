#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �� ����
int main(void) {
	int n;
	scanf("%d", &n);

	if ((n % 2) == 0) //¦��
		printf("CY"); 
	else //Ȧ��
		printf("SK");
	return 0;
}