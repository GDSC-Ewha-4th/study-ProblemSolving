#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int palindrome(char* s, bool deleted, int start, int end) {
	while (start < end) {
		if (s[start] == s[end]) {
			start++;
			end--;
		}
		else {
			if ((!deleted) &&(palindrome(s, true, start + 1, end) == 0) || (palindrome(s, true, start, end - 1) == 0))
				return 1;
			return 2;
		}
		
	}

	return 0;
}
int main(void) {
	int n;
	int ans;

	scanf("%d", &n);
	char** s = (char**)malloc(n * sizeof(char*)); //동적 할당 

	for (int i = 0; i < n; i++) {
		s[i] = (char*)malloc(100001 * sizeof(char));
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		ans = palindrome(s[i], false, 0, strlen(s[i]) - 1);
		printf("%d\n", ans);
	}

	for (int i = 0; i < n; i++) {
		free(s[i]);
	}
	free(s);

	return 0;
}