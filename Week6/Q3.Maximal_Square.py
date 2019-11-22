class Solution:

    ''' O(mn) / O(mn) '''
    def maximalSquare(self, matrix):
        
        max_len = 0

        if len(matrix) == 0 : return 0
        
        rows = len(matrix)
        cols = len(matrix[0])
        
        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                if matrix[i-1][j-1] == '1':
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]),dp[i-1][j-1]) + 1
                    max_len = max(max_len, dp[i][j])
        
        return max_len * max_len