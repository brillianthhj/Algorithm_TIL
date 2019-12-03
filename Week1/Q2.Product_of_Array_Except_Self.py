class Solution:
    def productExceptSelf(self, nums):
        length = len(nums)
        L = [1] * length
        R = [1] * length
        ans = [0] * length
        
        for i in range(1, length):
            L[i] = L[i-1] * nums[i-1]
            
        for i in range(length-1, 0, -1):
            R[i-1] = R[i] * nums[i]
            
        for i in range(length):
            ans[i] = L[i] * R[i]
        
        return ans

nums = [1,2,3,4]
s = Solution()
print(s.productExceptSelf(nums))