class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        l=[]
        for i in range(0,len(nums)-2,3):
            if(nums[i+2]-nums[i]<=k):
                l.append(nums[i:i+3])
            else:
                return []
        return l  