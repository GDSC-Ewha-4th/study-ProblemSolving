def palindrome(input):
    left = 0
    right = len(input) - 1
    
    while left < right:
        if input[left] == input[right]:
            left += 1
            right -= 1
        else:
            if left < right - 1:
                temp = input[:right] + input[right + 1:]
                if temp == temp[::-1]: # temp와 temp를 거꾸로 뒤집은 것이 같은지 확인
                    return 1
                
            if left + 1 < right:
                temp = input[:left] + input[left + 1:]
                if temp == temp[::-1]:
                    return 1
                    
            return 2
 
    
t = int(input())

for _ in range(t):
    result = palindrome(list(input()))
    
    if result == None:
        print(0)
    else:
        print(result)
