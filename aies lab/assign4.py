import math

def printBoard(board):
    print("\nCurrent board:")
    for row in board:
        print(' '.join(row))
    print()

# Function to evaluate the board
def evaluate(b):
    # Check rows
    for row in range(3):
        if b[row][0] == b[row][1] == b[row][2] and b[row][0] != '_':
            return 10 if b[row][0] == 'x' else -10

    # Check columns
    for col in range(3):
        if b[0][col] == b[1][col] == b[2][col] and b[0][col] != '_':
            return 10 if b[0][col] == 'x' else -10

    # Check diagonals
    if b[0][0] == b[1][1] == b[2][2] and b[0][0] != '_':
        return 10 if b[0][0] == 'x' else -10
    if b[0][2] == b[1][1] == b[2][0] and b[0][2] != '_':
        return 10 if b[0][2] == 'x' else -10

    return 0

def isMovesLeft(b):
    for row in b:
        for cell in row:
            if cell == '_':
                return True
    return False

def minimax(board, depth, isMaximizing):
    score = evaluate(board)

    # If we have a winner, return score
    if score == 10 or score == -10:
        return score - depth if score == 10 else score + depth

    # If no moves left, return 0
    if not isMovesLeft(board):
        return 0

    if isMaximizing:
        bestVal = -math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == '_':
                    board[i][j] = 'x'
                    bestVal = max(bestVal, minimax(board, depth + 1, False))
                    board[i][j] = '_'
        return bestVal
    else:
        bestVal = math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == '_':
                    board[i][j] = 'o'
                    bestVal = min(bestVal, minimax(board, depth + 1, True))
                    board[i][j] = '_'
        return bestVal

def findBestMove(board):
    bestVal = -math.inf
    bestMove = (-1, -1)
    for i in range(3):
        for j in range(3):
            if board[i][j] == '_':
                board[i][j] = 'x'
                moveVal = minimax(board, 0, False)
                board[i][j] = '_'
                if moveVal > bestVal:
                    bestMove = (i, j)
                    bestVal = moveVal
    return bestMove

def main():
    board = [
        ['_', '_', '_'],
        ['_', '_', '_'],
        ['_', '_', '_']
    ]
    printBoard(board)
    while isMovesLeft(board) and evaluate(board) == 0:
        # Human ('o') turn
        while True:
            try:
                move = input("Enter your move as 'row col' (0-based, space separated): ")
                row, col = map(int, move.strip().split())
                if 0 <= row < 3 and 0 <= col < 3 and board[row][col] == '_':
                    board[row][col] = 'o'
                    break
                else:
                    print("Invalid move, try again.")
            except Exception:
                print("Invalid input, try again.")

        printBoard(board)
        if not isMovesLeft(board) or evaluate(board) != 0:
            break

        # Computer ('x') turn
        print("Computer is making a move...")
        r, c = findBestMove(board)
        board[r][c] = 'x'
        printBoard(board)

    score = evaluate(board)
    if score == 10:
        print("Computer wins!")
    elif score == -10:
        print("You win!")
    else:
        print("It's a draw!")

if __name__ == "__main__":
    main()
