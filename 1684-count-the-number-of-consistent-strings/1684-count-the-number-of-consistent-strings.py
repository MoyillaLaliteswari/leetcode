class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        cnt = 0
        allowed_set = set(allowed)  
        for word in words:
            if all(char in allowed_set for char in word): 
                cnt += 1
        return cnt
            
        