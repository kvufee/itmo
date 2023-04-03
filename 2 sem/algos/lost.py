def dfs(adjList, visList, first, tSort):
    visList[first] = True
    for second in adjList[first]:
        if not visList[second]:
            dfs(adjList, visList, second, tSort)
    tSort.append(first)

n, m = map(int, input().split())

adjList = [[] for i in range(n+1)]
visList = [False] * (n + 1)
tSort = []

for i in range(m):
    a, b = map(int, input().split())
    adjList[a].append(b)


for first in range(1, n + 1):
    if not visList[first]:
        dfs(adjList, visList, first, tSort)

new = {}
for i, first in enumerate(reversed(tSort)):
    new[first] = i + 1

for first in range(1, n + 1):
    print(new[first], end=' ')