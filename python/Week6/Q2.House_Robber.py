class Solution:

    ''' O(N) / O(1) '''
    def rob(self, nums):
        
        if len(nums) == 0 : return 0
        if len(nums) == 1 : return nums[0]
        if len(nums) == 2 : return max(nums[0], nums[1])
        
        prv_max = nums[0]
        max_sum = max(nums[0], nums[1])
        
        for i in range(2,len(nums)):
            tmp = max_sum
            max_sum = max(prv_max + nums[i], max_sum)            
            prv_max = tmp
            
        return max_sum