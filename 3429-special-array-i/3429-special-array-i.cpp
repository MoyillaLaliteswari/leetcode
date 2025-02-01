class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()<=1){
            return true;
        }
        else{
            int cnt=0;
            for(int i=1;i<nums.size();i++){
                if((nums[i-1]%2==0 and nums[i]%2==1) or (nums[i-1]%2==1 and nums[i]%2==0)){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};