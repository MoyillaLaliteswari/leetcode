class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        // mp[nums[0]]=0;
        int l;
        int r;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                l=mp[rem];
                r=i;
                break;
            }
            mp[nums[i]]=i;
        }
        return {l,r};
    }
};