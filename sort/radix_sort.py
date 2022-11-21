def countingSort(arr, flag):
    data = [0] * len(arr)
    count_arr = [0] * 256

    for i in range(0, len(arr)):
        index = arr[i] // flag
        count_arr[index % 10] += 1

    for i in range(1, 10):
        count_arr[i] += count_arr[i - 1]


    iter = len(arr) - 1
    while iter >= 0:
        index = arr[i] // flag
        data[count_arr[index % 10] - 1] = arr[i]
        count_arr[index % 10] -= 1
        iter -= 1

    for i in range(0, len(arr)):
        arr[i] = data[i]


def radixSort(arr):
    maxN = 0
    for i in range(len(arr) - 1):
        if arr[i] > maxN:
            maxN = arr[i]

    flag = 1
    while maxN // flag >= 1:
        countingSort(arr, flag)
        flag *= 10

    return arr


arr = list(map(int, input().split()))

print(radixSort(arr))