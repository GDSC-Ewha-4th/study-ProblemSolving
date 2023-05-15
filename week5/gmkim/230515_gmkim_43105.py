"""
Programmers 43105 정수 삼각형
문제 링크: https://school.programmers.co.kr/learn/courses/30/lessons/43105
"""

import sys
from collections import deque

input = sys.stdin.readline

def solution(triangle):
    for i in range(1, len(triangle)):
        for j in range(i + 1):
            if j == 0:
                triangle[i][j] += triangle[i - 1][0]
            elif i == j:
                triangle[i][j] += triangle[i - 1][-1]
            else:
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j])
    answer = max(triangle[-1])
    return answer

if __name__ == "__main__":

    triangle = [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]

    print(solution(triangle))