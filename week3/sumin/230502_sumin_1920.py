def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None

n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
cnt = 0

a.sort()

for i in range(m):
    result = binary_search(a, b[i], 0, n - 1)
    
    if result == None:
        print("0")
    else:
        print("1")
