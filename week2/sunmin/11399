# 코드 참고

n = int(input())  # 첫째줄 입력
peoples = list(map(int, input().split()))  # 기다리는 사람들 리스트 형태로 입력 받음

peoples.sort()  # 작은 순서대로 정렬
answer = 0  # 정답 변수를 0으로 만듭니다.

for x in range(1, n+1):
    answer += sum(peoples[0:x])  # 리스트의 0번째 수부터 x번째 수까지를 더해줍니다.
print(answer)  # 정답 제출
