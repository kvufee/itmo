n = int(input())
arr = list(map(int, input().split()))

flag = 0

for i in range(1, n + 1):

    if (2 * i <= n and arr[i] > arr[2 * i]):
        flag = 1
        break

    elif (2 * i + 1 <= n and arr[i] > arr[2 * i + 1]):
        flag = 1
        break

if flag == 1:
    print('NO')
else:
    print('YES')