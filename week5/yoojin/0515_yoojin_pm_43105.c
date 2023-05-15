#include <stdio.h>

int triangle[][5] = {
    {7}, 
    {3, 8},
    {8, 1, 0},
    {2, 7, 4, 4}, 
    {4, 5, 2, 6, 5}};

int dp[501][501];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solution(int** triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    int size = sizeof(triangle) / sizeof(triangle[0]); //

    for (int i = 1; i < size; i++) { 
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
}

    for (int i = 0; i < size; i++) {
        answer = max(answer, dp[size - 1][i]);}
    return answer;
}

int main(void) {
    printf("%d", solution(triangle));
    return 0;
}