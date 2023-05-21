def find_network_dfs(connection, check, idx, network):
    for c in connection[idx]:
        if check[c] == 0:
            check[ㅊ] = network
            find_network_dfs(connection, check, c, network)


def solution(n, computers):
    # 직접 / 간접 연결 모두 컴퓨터가 정보를 교환할 수 있게 한다.
    answer = 0
    
    check = [0 for _ in range(n)] # 각 컴퓨터가 저장하고 있는 배열 정보
    connection = [[] for _ in range(n)]
    
    for y in range(n):
        for x in range(y+1, n):
            if computers[y][x] == 1:
                connection[y].append(x)
                connection[x].append(y)
    
    network = 0
    for i in range(n):
        if check[i] == 0:
            network += 1
            check[i] = network
            find_network_dfs(connection, check, i, network)
            
    return network
