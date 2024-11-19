class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        long long mx=0;
        int i=0,j=i+1;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(i>=k){
                int j=nums[i-k];
                mp[j]--;
                sum-=j;
                if(mp[j]==0){
                    mp.erase(j);
                }
            }
            if(i>=k-1 and mp.size()==k){
                mx=max(mx,sum);
            }
        }
        return mx;
    }
};