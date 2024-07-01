class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if 1 not in nums:
            return 1
        nums.sort()
        d={}
        a=nums.index(1)
        for i in range(a,len(nums)):
            if nums[i] not in d:
                d[nums[i]]=1
            else:
                d[nums[i]]+=1
        b=max(d)
        for i in range(1,b):
            if i not in d:
                return i
        else:
            return b+1