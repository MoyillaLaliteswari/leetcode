class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        d=[0]*k
        for i in arr:
            rem=i%k
            if(rem<0):
                rem+=k
            d[rem]+=1
        if d[0] %2 !=0:
            return False
        for i in range(1,k):
            if d[i]!=d[k-i]:
                return False
        return True
                
        
            