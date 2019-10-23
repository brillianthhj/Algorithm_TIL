import collections

class Solution:
    def fourSum(self, nums, target):
        
        answer = set()
        twosum_dict = collections.defaultdict(set)
        nums.sort()

        for i in range(len(nums)):
            for j in range(i + 1 , len(nums)):
                value = (nums[i] + nums[j])

                for complement in twosum_dict[target - value]:
                    answer.add(tuple(list(complement) + [nums[i], nums[j]]))
            
            for k in range(i):
                twosum_dict[nums[k] + nums[i]].add((nums[k], nums[i]))
       
        return list(answer)

nums = [1, 0, -1, 0, -2, 2]
target = 0
s = Solution()
ans = s.fourSum(nums, target)
print(ans) 