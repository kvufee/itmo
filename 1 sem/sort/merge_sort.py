n = int(input())
arr = [int(i) for i in input().split()]

def merge(first, second):
    result = []
    i = j = 0

    while i < len(first) and j < len(second):
        if first[i] < second[j]:
            result.append(first[i])
            i += 1
        else:
            result.append(second[j])
            j += 1

    if i < len(first):
        result += first[i:]
    if j < len(second):
        result += second[j:]

    return result

def MergeSort(array):
    if len(array) <= 1:
        return array

    mid = len(array) // 2
    left = MergeSort(array[:mid])
    right = MergeSort(array[mid:])

    return merge(left, right)

arr = MergeSort(arr)

for i in range(len(arr)):
    print(arr[i], end = ' ')