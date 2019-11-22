class Solution:
    
    def combinationSum(self, candidates, target):

        self.ans = []
        self.ans_tmp = []
        candidates.sort()
        
        def recursion(candidates, target):

            for i, value in enumerate(candidates):
                re_target = target - value

                if re_target >= value:
                    self.ans_tmp.append(value)
                    recursion(candidates[i:], re_target)

                elif re_target == 0:
                    self.ans_tmp.append(value)
                    self.ans.append(self.ans_tmp)
                    self.ans_tmp = self.ans_tmp[:-1]
                
                else:
                    continue
                
            else:
                self.ans_tmp = self.ans_tmp[:-1]

        recursion(candidates, target)
        
        return self.ans


# candidates = [2,3,5]
# target = 8
candidates = [8,7,4,3]
target = 11
s = Solution()
print(s.combinationSum(candidates, target))