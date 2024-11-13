class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long cnt=0;

        for(int i=0;i<n;i++){
            int left=i+1;
            auto l=lower_bound(nums.begin()+left,nums.end(),lower-
            nums[i])-nums.begin();
            auto r=upper_bound(nums.begin()+left,nums.end(),upper-
            nums[i])-nums.begin();
            cnt+=(r-l);
        }
        return cnt;
    }
};