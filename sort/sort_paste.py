n = int(input())
arr = list(map(int, input().split()))

for i in range(1, n):
    for j in range(i, 0, -1):
        if j > 0 and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]

for i in range(len(arr)):
    print(arr[i], end = ' ')