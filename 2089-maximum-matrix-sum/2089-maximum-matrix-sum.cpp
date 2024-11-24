class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mini=INT_MAX;
        bool flag=false;
        for(auto& row:matrix){
            for(int x: row){
                mini=min(mini,abs(x));
                if(x<0){
                    sum-=x;
                    flag=!flag;
                }
                else{
                    sum+=x;
                }
            }
        }
        return (flag)? sum-2 * mini : sum;
    }
};