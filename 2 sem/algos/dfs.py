adjList = []
visList = []

nums = list(map(int, input().split()))
flag = False

def dfs(adjList, visList, nums[0], nums[1]):
    visList[nums[0]] = 1;

    for i in range(len(adjList)):
        if visList[i] == 0:
            dfs(adjList, visList, adjList[nums[0]][i], nums[0])
        elif visList[i] == 1 and nums[0] != nums[1]:
            flag = True
    
    visList[nums[0]] = 2

