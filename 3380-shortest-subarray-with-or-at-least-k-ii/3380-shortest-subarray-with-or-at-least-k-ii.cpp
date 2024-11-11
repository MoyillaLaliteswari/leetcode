class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>bits(32);
        int w=0,mini=INT_MAX;
        for(int l=0,r=0;r<nums.size();r++){
            if(nums[r]>=k) return 1;
            w|=nums[r];
            for(int i=0;i<bits.size();i++){
                bits[i] += (nums[r]>>i)&1;
            }
            while(w>=k){
                mini=min(mini,r-l+1);
                for(int i=0;i<bits.size();i++){
                    bits[i] -= (nums[l]>>i)&1;
                    if(bits[i]==0) w&= ~(1<<i);
                }
                l++;
            }
        }
        return mini==INT_MAX ? -1 : mini;
    }
};