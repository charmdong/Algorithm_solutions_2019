def solution(bishops):
    answer = 0

    for bishop in bishops:
        col = ord(bishop[0]) - 64
        row = int(bishop[1])
        board[row][col] = 1
        
        for i in range(4) :
            nextRow = row + dy[i]
            nextCol = col + dx[i]

            while isInBoard(nextRow, nextCol) :
                board[nextRow][nextCol] = 1
                nextRow += dy[i]
                nextCol += dx[i]
    
    for row in board :
        #print(row)
        answer += len(list(filter(lambda x : x == 0, row)))

    return answer - 17


def isInBoard(y, x):
    if y > 0 and y < 9:
        if x > 0 and x < 9:
            return True
        else:
            return False
        return False


dy = [-1, -1, 1, 1]
dx = [-1, 1, -1, 1]
board = [[0 for row in range(9)] for col in range(9)]