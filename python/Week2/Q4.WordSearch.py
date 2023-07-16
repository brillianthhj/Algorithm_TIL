class Solution:
    def exist(self, board, word):

        '''
        Time complexity : O(SMN), Space complexity : O(S)
        '''

        r_len = len(board)
        c_len = len(board[0])
        
        def word_exist(r, c, s):
            
            # 1. 종결 조건
            if len(word) == s + 1 :
                return True
            
            # 2. 현재 노드가 유효하지 않을 때 빠져나갈 구멍
            if r < 0 or c < 0 or r >= r_len or c >= c_len or board[r][c] != word[s]:
                return False
            
            board[r][c] = '0'

            # 3. 다음 단계로 넘어가기 위한 조건
            if c - 1 >= 0 and board[r][c - 1] == word[s + 1]:
                if word_exist(r, c - 1, s + 1):
                    return True
            
            if c + 1 < c_len and board[r][c + 1] == word[s + 1]:
                if word_exist(r, c + 1, s + 1):
                    return True
            
            if r - 1 >= 0 and board[r - 1][c] == word[s + 1]:
                if word_exist(r - 1, c, s + 1):
                    return True
            
            if r + 1 < r_len and board[r + 1][c] == word[s + 1]:
                if word_exist(r + 1, c, s + 1):
                    return True
            
            board[r][c] = word[s]

        start = [[i, j] for i in range(r_len) for j in range(c_len) if board[i][j] == word[0]]
           
        for rr, cc in start:
            if word_exist(rr, cc, 0):
                return True
            
        return False


    ##########################################
    ########### Similar best answer ##########
    ##########################################
    def exist(self, board, word):
        if not board or not str:
            return False

        m = len(board)
        n = 0
        if board[0]:
            n = len(board[0])

        word_len = len(word)

        def _dfs(x, y, word_index):
            if word_index == word_len:
                return True

            if x < 0 or x >= m or y < 0 or y >= n or board[x][y] != word[word_index]:
                print("No : ", "current : ", x, y, word_index)
                return False

            print("r , c = (", x, ", ", y, ", ", word_index, ")")
            
            board[x][y] = '0'
            #up
            if _dfs(x-1, y, word_index+1):
                print("↑ : ", "current : ", x, y, word_index)
                return True
            #down
            if _dfs(x+1, y, word_index+1):
                print("↓ : ", "current : ", x, y, word_index)
                return True
            #left
            if _dfs(x, y-1, word_index+1):
                print("← : ", "current : ", x, y, word_index)
                return True
            #right
            if _dfs(x, y+1, word_index+1):
                print("→ : ", "current : ", x, y, word_index)
                return True
            board[x][y] = word[word_index]

            return False

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    ans = _dfs(i, j, 0)
                    if ans:
                        print("*****", ans)
                        return True
        return False
