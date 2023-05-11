def solution(numbers, target):
    answer = 0
    leaves = [0]
    
    for x in numbers:
        temp = []
        for parent in leaves:
            temp.append(parent + x)
            temp.append(parent - x)
        leaves = temp
    
    for leaf in leaves:
        if leaf == target:
            answer += 1
            
    return answer
