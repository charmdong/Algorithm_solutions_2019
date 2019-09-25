def solution(numList, k) :
    result = ""
    numList.sort()
    dfs(0, result, numList)
    return resultList[k-1]

def dfs(index, result, numList) : 
    if len(result) == len(numList) :
        resultList.append(result)

    for i in range(len(numList)) :
        if visited[i] == False :
            result = result + numList[i]
            visited[i] = True;
            dfs(i + 1, result, numList)
            visited[i] = False;
            result = result[: -1]
            
numList = input().split()
k = int(input())
visited = [False for i in range(len(numList))]
resultList = []
print(solution(numList, k))