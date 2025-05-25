def checkboard(size):
    board=[ [0]*size for i in range(size)]
    x=0
    y=0
    stillalive=True
    while stillalive:
        board[x][y]=1
        if( x+2 < size and y+1 < size and board[x+2][y+1] == 0):
            x += 2
            y += 1
        elif( x+2 < size and y-1 >= 0 and board[x+2][y-1] == 0):
            x += 2
            y -= 1
        elif( x-2 >= 0 and y+1 < size and board[x-2][y+1] == 0):
                x -= 2
                y += 1
        elif( x-2 >= 0 and y-1 >= 0 and board[x-2][y-1] == 0):
                    x -= 2
                    y -= 1
        elif( x+1 < size and y+2 < size and board[x+1][y+2] == 0):
                    x += 1
                    y += 2
        elif( x-1 >= 0 and y+2 < size and board[x-1][y+2] == 0):
                    x -= 1
                    y += 2
        elif( x+1 < size and y-2 >= 0 and board[x+1][y-2] == 0):
                    x += 1
                    y -= 2
        elif( x-1 >= 0 and y-2 >= 0 and board[x-1][y-2] == 0):
                    x -= 1
                    y -= 2
        else:
              stillalive=False;


    full=True  
    for i in range(size):
        for j in range(size):
            if board[i][j] == 0:
                full=False
                break



    print("YES" if full else "NO")


checkboard(8)