class Solution {
public:
int t=0;
int findTargetSumWays(vector<int>& nums, int target) {
        cal(nums,0,0,target);
        return t;
    }
private:
    void cal(vector<int>&nums,int curr,int sum,int target){
if(curr==nums.size()){
    if(sum==target){
        t++;
    }
}
    else{
        cal(nums,curr+1,sum+nums[curr],target);
        cal(nums,curr+1,sum-nums[curr],target);
    
}
    }
    
};