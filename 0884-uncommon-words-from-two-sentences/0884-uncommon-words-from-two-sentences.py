class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s11=s1.split()
        s22=s2.split()
        word=Counter(s11+s22)
        result=[]
        for i,j in word.items():
            if(j==1):
                result.append(i)
        return result
            
        