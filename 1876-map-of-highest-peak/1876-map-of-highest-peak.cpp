class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>res(n,vector<int>(m,n+m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    res[i][j]=0;
                }else{
                    if(i>0){
                        res[i][j]=min(res[i][j],res[i-1][j]+1);
                    }
                    if(j>0){
                        res[i][j]=min(res[i][j],res[i][j-1]+1);
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i<n-1){
                    res[i][j]=min(res[i][j],res[i+1][j]+1);
                }
                if(j<m-1){
                    res[i][j]=min(res[i][j],res[i][j+1]+1);
                }
            }
        }
        return res;
    }
};