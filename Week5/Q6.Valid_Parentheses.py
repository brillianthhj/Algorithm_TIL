class Solution:
    def isValid(self, s: str) -> bool:
        # parenthesis = s.split('')
        m = { '{' : '}', '[' : ']', '(' : ')', '}' : 'None', ']' : 'None', ')' : 'None' }
        stack = []
        res = False
        
        for i in range(len(s)):
            if stack and m[stack[-1]] == s[i]:
                stack.pop()
            else :
                stack.append(s[i])
        
        if stack:
            res = False
        else:
            res = True
            
        return res

my_string = "([)]"
s = Solution()
print(s.isValid(my_string))