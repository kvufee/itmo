n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))

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

def Set(arr):
    ans = []
    for i in arr:
        if not ans or i != ans[-1]:
            ans.append(i)
    return ans

def similar_arrays(first, second):
    if first == second:
        return 'YES'
    else:
        return 'NO'

arr1 = quickSort(arr1)
arr2 = quickSort(arr2)
arr1 = Set(arr1)
arr2 = Set(arr2)

print(similar_arrays(arr1, arr2))