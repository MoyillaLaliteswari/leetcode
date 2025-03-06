class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n=len(grid)
        miss=(n*n)*(1+n*n)//2
        seen=set()
        dup=-1
        for row in grid:
            for num in row:
                if num not in seen:
                    seen.add(num)
                    miss-=num
                else:
                    dup=num
        return [dup,miss]
        