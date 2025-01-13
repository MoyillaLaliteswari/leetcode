class Solution:
    def maxArea(self, height: List[int]) -> int:
        # l=[]
        # for i in range(0,len(height)//2):
        #     for j in range(i,len(height)):
        #         n=min(height[i],height[j])
        #         m=j-i
        #         a=n*m
        #         l.append(a)
        # return max(l)
        i=0
        j=len(height)-1
        l=[]
        while(i<=j):
            n=min(height[i],height[j])
            m=j-i
            a=n*m
            l.append(a)
            if(height[i]<height[j]):
                i=i+1
            else:
                j=j-1
        return(max(l))
    
            


