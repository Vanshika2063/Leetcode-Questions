class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        def check(i,j,num): 
            # cheking for num in the same col
            for x in range(n):
                if board[x][j] == num:
                    return False
                
            # checking for the num in the same row
            for x in range(n):
                if board[i][x] == num:
                    return False
                
            # basically wer are checking for the presence of the rnumber in the 
            # 3 x 3 blocks
            blockX = i -  i % 3
            blockY =  j - j % 3
            for i in range(blockX,blockX+3):
                for j in range(blockY,blockY+3):
                    if board[i][j] == num:
                        return False
            return True
        
        def fillNum(i,j,ch): board[i][j] = ch
        n = len(board)  
        
        # our recursion is based on the fact that we will traverse across the entire grid and
        # call the recursion function only when we want to fill a particular cell
        
        
        def solve():
            # iterate over the entier grid    
            for i in range(n):
                for j in range(n):
                    if board[i][j] == ".":
                        # check for all the posibilities
                        for x in range(1,10):
                            x  = str(x)
                            # if fillling that position is possible filin that number
                            if check(i,j,x):
                                fillNum(i,j,x)
                                # if making the previous move results in the solving of the 
                                # sudoke, we will get true
                                # else we will get false and we will backtrack, by
                                # removing the number and placing '.' again
                                if solve():
                                    return True
                                fillNum(i,j,'.')
                        # if we are not able to fill any number in that gap, it means that there
                        # is an other number which is blocking the right answer from being iflled
                        # so we are backtracking frfom here to change the previous choices
                        return False
            return True
                           
          
        solve()
        # return board
