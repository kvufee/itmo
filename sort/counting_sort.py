def countingSort(arr):
    data = [0] * len(arr)
    count_arr = [0] * 10

    for i in range(0, len(arr)):
        count_arr[arr[i]] += 1

    for i in range(1, 10):
        count_arr[i] += count_arr[i - 1]


    iter = len(arr) - 1
    while iter >= 0:
        data[count_arr[arr[iter]] - 1] = arr[iter]
        count_arr[arr[iter]] -= 1
        iter -= 1

    for i in range(0, len(arr)):
        arr[i] = data[i]
    
    return arr



nums = int(input())
arr = list(map(int, input().split()))

arr = countingSort(arr)
print(arr)