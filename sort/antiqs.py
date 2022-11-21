n = int(input())
arr = list(range(1, n + 1))

def aQsort(arr):
    for i in range(2, n):
        arr[i], arr[i // 2] = arr[i // 2], arr[i]
    for i in range(len(arr)):
        print(arr[i], end = ' ')

aQsort(arr)