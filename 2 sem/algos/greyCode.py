n = int(input())

def grayCode(n):
    if n == 0:
        return ['']
    else:
        result = grayCode(n-1)
        return ['0' + code for code in result] + ['1' + code for code in reversed(result)]

ans = grayCode(n)

for i in range(len(ans)):
    print(ans[i], end = "\n")