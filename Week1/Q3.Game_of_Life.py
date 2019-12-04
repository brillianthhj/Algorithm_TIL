class Solution:
    def gameOfLife(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        direction = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1),
                    (1,-1), (1,0), (1,1)]
        rows = len(board)
        cols = len(board[0])
        
        for i in range(rows):
            for j in range(cols):

                num_live = 0
                for dirc in direction:
                    r = i + dirc[0]
                    c = j + dirc[1]
                    
                    if (r < rows and r >= 0) and (c < cols and c >= 0) and abs(board[r][c]) == 1:
                        num_live += 1
                        
                if board[i][j] == 1 and (num_live < 2 or num_live > 3):
                    board[i][j] = -1
                    
                elif board[i][j] == 0 and num_live == 3:
                    board[i][j] = 2
                    
        for i in range(rows):
            for j in range(cols):
                if board[i][j] > 0:
                    board[i][j] = 1
                else:
                    board[i][j] = 0
                                    
                    
board = [
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]

s = Solution()
s.gameOfLife(board)