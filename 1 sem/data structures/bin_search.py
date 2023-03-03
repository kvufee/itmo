def BinSearchL(arr, req_item):
    l = 0
    r = len(arr)
    
    while l < r and arr[l] < req_item:
        l += 1
    return l + 1

def BinSearchR(arr, req_item):
    l = 0
    r = len(arr) - 1

    while r >= 0 and arr[r] > req_item:
        r -= 1
    return r + 1


n = int(input())
arr = list(map(int, input().split()))
m = int(input())
reqs = list(map(int, input().split()))
for i in range(m):
    print(BinSearchL(arr, reqs[i]), BinSearchR(arr, reqs[i]))