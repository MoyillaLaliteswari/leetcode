class Solution:
    def trap(self, height: List[int]) -> int:
        l=0
        r=len(height)-1
        m1=height[l]
        m2=height[r]
        ans=0
        while(l<r):
            m1=max(m1,height[l])
            m2=max(m2,height[r])
            if(m1<m2):
                ans+=m1-height[l]
                l=l+1
            else:
                ans+=m2-height[r]
                r=r-1
        return ans
        



        