""" 17609 - 회문
<문제 설명>
- 앞과 뒤 방향 모두에서 같은 순서의 문자로 구성된 문자열에 회문이고, 한 문자를 삭제하여 회문으로 만들 수 있다면 이를 유사 회문이라고 한다.
{
    회문: 0, 유사회문: 1, 그 외: 2
}

"""

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
T = int(input()) ##  문자열의 개수

def check_palindrome(s, l, r, rm):
    # l, r  = 0, len(s)-1
    # rm = 0
    # print(s, l, r)
    while l  < r: ## 같은 위치를 가리켜도 당연히 멈춰야 함,,

        if s[l] == s[r]:
            l += 1
            r -= 1
        else:
            if rm == 0: ## 아무것도 제거하지 않았을때
                if check_palindrome(s, l+1, r, 1) == 0 or check_palindrome(s, l, r-1, 1) == 0: ## 하나를 제거했을때 그 문자열이 회문이 되는 경우
                    # return 1 ## 나머지 문자열을 돌았기 때문에 부분 회문으로 멈출 수 있음
                    rm += 1
                    return rm
                else: ## 하나의 문자열을 제거해도 회문이 되지 않는 경우
                    return 2
            else: ## 이미 제거했는데 또 안맞으면 <그외>에 해당
                return 2

    return 0



for t in range(T):
    s = input().strip()
    ret = check_palindrome(s, 0, len(s)-1, 0)
    print(ret)
