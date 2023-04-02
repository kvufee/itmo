def dfs(v, used, g, topsort):
    used[v] = True
    for now in g[v]:
        if not used[now]:
            dfs(now, used, g, topsort)
    topsort.append(v)

n, m = map(int, input().split())
g = [[] for _ in range(n+1)]
for i in range(m):
    from_, to = map(int, input().split())
    g[from_].append(to)

used = [False] * (n+1)
topsort = []
for i in range(1, n+1):
    if not used[i]:
        dfs(i, used, g, topsort)

reversed(topsort)
ans = [0] * (n+1)
for i in range(1, n+1):
    ans[topsort[i-1]] = i

print(*ans[1:])
