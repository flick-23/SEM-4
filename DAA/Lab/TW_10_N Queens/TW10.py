# Number of queens

def is_attack(i, j, board):
    for k in range(len(board)):
        if board[i][k] == 1 or board[k][j] == 1:
            return True
    for k in range(len(board)):
        for l in range(len(board)):
            if (k+l == i+j) or (k-l == i-j):
                if board[k][l] == 1:
                    return True
    return False


def N_queen(n, board):
    if n == 0:
        return True
    for i in range(len(board)):
        for j in range(len(board)):
            if (not(is_attack(i, j, board))) and (board[i][j] != 1):
                board[i][j] = 1
                if N_queen(n-1, board) == True:
                    return True
                board[i][j] = 0

    return False


def main():
    ch = 1
    while ch == 1:
        print("Press 1 to Test the program")
        print("Press 2 to Exit the program")

        ch = int(input("Enter your choice :: "))
        if ch == 1:
            N = int(input("Enter the number of queens :: "))

            board = [[0]*N for _ in range(N)]

            N_queen(N, board)

            for i in board:
                print(i)
            print()

        elif ch == 2:
            print("Exiting ...")
            ch = 0

        else:
            print("Invalid Choice!!")


if __name__ == "__main__":
    main()
