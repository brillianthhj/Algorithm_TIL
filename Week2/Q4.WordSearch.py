class Solution:
    def exist(self, board, word):

        '''
        Time complexity : O(SMN), Space complexity : O(S)
        '''

        ans = False
        r_len = len(board)
        c_len = len(board[0])
        
        def word_exist(r, c, s):
            print("r , c = (", r, ", ", c, ")")
            
            # 1. 종결 조건
            if len(word) == s + 1 :
                return True
            
#             board[r][c] = '0'

            # 2. 다음 단계로 넘어가기 위한 조건
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
            
            # 3. 현재 노드가 유효하지 않을 때 빠져나갈 구멍
            else :
                return False
            
#             board[r][c] = word[s]
        
    
        start = [[i, j] for i in range(r_len) for j in range(c_len) if board[i][j] == word[0]]
           
        for rr, cc in start:
            ans = word_exist(rr, cc, 0)
            if ans:
                return ans
            
        return ans