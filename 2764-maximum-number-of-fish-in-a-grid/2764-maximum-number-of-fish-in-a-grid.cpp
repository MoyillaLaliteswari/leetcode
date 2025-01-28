class Solution {
public:
    int cells(int row,int col,vector<vector<int>>&grid){
        int rows=grid.size(),cols=grid[0].size();
        if(row<0 || col<0 || row>=rows || col>=cols || grid[row][col]==0) return 0;
        int curr=grid[row][col];
        grid[row][col]=0;
        curr+=cells(row+1,col,grid);
        curr+=cells(row-1,col,grid);
        curr+=cells(row,col+1,grid);
        curr+=cells(row,col-1,grid);
        return curr;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size(),maxi=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]!=0){
                    maxi=max(maxi,cells(row,col,grid));
                }
            }
        }
        return maxi;
    }
};