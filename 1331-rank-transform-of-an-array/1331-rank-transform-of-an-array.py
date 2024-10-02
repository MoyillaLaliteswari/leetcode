class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        k=[]
        for i in arr:
            k.append(i) 
        k=list(set(k))
        k.sort()
        print(k)
        d={}
        for i in range(len(k)):
            d[k[i]]=i
            
        k=[]
        for i in arr:
            if i in d:
                k.append(d[i]+1)
        return k
            
            
            
        
        
            
            
        
        