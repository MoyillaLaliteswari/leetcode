class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
       int maxi=1;
       int mini=1;
       int cnt=1;
       for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                cnt=1;
            } 
       } 
       int cnt2=1;
       for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]<nums[i]){
                cnt2++;
                mini=max(mini,cnt2);
            }
            else{
                cnt2=1;
            }
       }
       return max(maxi,mini);
    }
};