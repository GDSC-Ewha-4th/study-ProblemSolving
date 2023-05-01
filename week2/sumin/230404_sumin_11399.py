// 1. 소요시간을 오름차순으로 정렬
// 2. (사람 수 - 인덱스) * 해당 인덱스의 소요시간을 더하기 
// (n=5라고 하면 가장 시간이 적게 걸리는 0번 인덱스 값은 5번 더해지고, 그 다음으로 적게 걸리는 1번 인덱스 값은 4번 더해지고 ...)

n = int(input())
array = list(map(int, input().split()))
array.sort()
result = 0

for i in range(n):
    result += (n-i) * array[i]
    
print(result)
