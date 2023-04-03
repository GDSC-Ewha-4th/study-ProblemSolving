# 시간 꽤 걸림 다시보기!
def solution(n, lost, reserve):
    # 여벌 체육복 가져온 학생이 도난당한 경우
    new_lost = set(lost) - set(reserve)
    new_reserve = set(reserve) - set(lost)
    
    answer = n - len(new_lost) # 체육복 빌려주기 전에 체육수업을 들을 수 있는 학생 수
    
    # 체육복 도난당한 학생에게 체육복 빌려주기
    for x in new_lost: 
        if x - 1 in new_reserve:
            new_reserve.remove(x - 1)
        elif x + 1 in new_reserve:
            new_reserve.remove(x + 1)
        else:
            continue
        answer += 1
    
    return answer
