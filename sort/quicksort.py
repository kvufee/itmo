n = int(input())
arr = [int(i) for i in input().split()]

def quickSort(arr):
    left = []
    right = []
    center = []

    if len(arr) <= 1:
        return arr
    flag = arr[0]
    for i in range(len(arr)):
        if arr[i] < flag:
            left.append(arr[i])
    for i in range(len(arr)):
        if arr[i] > flag:
            right.append(arr[i])
    for i in range(len(arr)):
        if arr[i] == flag:
            center.append(arr[i])

    return quickSort(left) + center + quickSort(right)

arr = quickSort(arr)

for i in range(len(arr)):
    print(arr[i], end = ' ')