class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(maxi==nums[i]){
                len++;
            }
            else{
                len=0;
            }
            m=max(m,len);
        }
        return m;
    }
};