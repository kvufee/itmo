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

size = list(map(int, input().split()))
raft = []
for i in range(size[0]):
    raft.append(list(map(int, input().split())))
k = int(input())
mesk = list(map(int, input().split()))
count = 0
raft_mass = []
max_r = 0

for i in range(len(raft)):
    raft_mass += raft[i]

mesk = quickSort(mesk)
raft_mass = quickSort(raft_mass)

for i in range(len(raft_mass)):
    if raft_mass[i] > max_r:
        max_r = raft_mass[i]

for i in range(0, len(mesk)):
    if mesk[i] <= raft_mass[i]:
        count += 1
        mesk = mesk[i:]
        raft_mass = raft_mass[i:]

print(mesk)
print(raft_mass)
print(count)