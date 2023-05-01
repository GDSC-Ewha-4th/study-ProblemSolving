# 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 빌려주기 가능
# 체육수업을 들을 수 있는 학생의 최댓값 
# 무조건 뒤에 번호에 옷을 빌려준다.

def solution(n, lost, reserve):
    answer = 0
    # set 중복제거 오름차순 정렬
    reserve_del = set(reserve) - set(lost) # 1, 3, 5
    lost_del = set(lost)- set(reserve) # 2, 4
   
    # 앞, 뒤 체크
    for i in reserve_del: #1, 3, 5
        if i-1 in lost_del: #0, 2, 4
            lost_del.remove(i-1) #remove : 2, 4
        elif i+1 in lost_del: #2, 4, 6
            lost_del.remove(i+1) # already remove
   
    answer = n - len(lost_del)
    return answer
