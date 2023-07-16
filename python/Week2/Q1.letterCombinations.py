class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

      '''
      Time complexity : O(3^N × 4^M), Space complexity : O(N)
      '''
        
        phone = {"2":["a", "b", "c"], 
               "3":["d", "e", "f"], 
               "4":["g", "h", "i"], 
               "5":["j", "k", "l"],
               "6":["m", "n", "o"], 
               "7":["p", "q", "r", "s"], 
               "8":["t", "u", "v"], 
               "9":["w", "x", "y", "z"]}
        
        words = [0]*(len(digits)+1)
        
        def backtrack(level, digits):
            
            if level == len(digits) :
                output.append("".join(words[1:len(digits)+1]))
            else:
                for i in range(len(phone[digits[level]])):
                    words[level+1] = phone[digits[level]][i]
                    backtrack(level+1, digits)        
        
        output = []
        if digits:
            backtrack(0, digits)
        return output