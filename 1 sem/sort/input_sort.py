n = int(input())
data = []
for i in range(n):
    data.append(list(map(int, input().split())))

for i in range(len(data)):
    for j in range(len(data) - 1):
        if data[j][1] < data[j + 1][1]:
            data[j], data[j + 1] = data[j + 1], data[j]

for i in range(len(data)):
    for j in range(len(data) - 1):
        if data[j][1] == data[j + 1][1] and data[j][0] > data[j + 1][0]:
            data[j], data[j + 1] = data[j + 1], data[j]

for i in range(len(data)):
    print(*data[i])