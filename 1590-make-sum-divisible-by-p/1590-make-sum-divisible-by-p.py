class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        
        s=sum(nums)
        k=s%p
        if k in nums:
            return 1
        elif(k==0):
            return 0
        else:
            n=len(nums)
            cur=0
            d={0:-1}
            for i,r in enumerate(nums):
                cur=(cur+r)%p
                prefix=(cur-k+p)%p
                if prefix in d:
                    l=i-d[prefix]
                    n=min(n,l)
                d[cur]=i
        if(n==len(nums)):
            return -1
        else:
            return n
                
                
                
                    
            
            