class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt=0;
        long long n=nums.size();
        map<int,int>mp;
        for (int i=0;i<nums.size();i++){
            int l=nums[i]-i;
            cnt+=mp[l];
            mp[l]++;
        }
        return (n*(n-1))/2-cnt;
    }
};