class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int num:nums){
            ans+=int(floor(log10(num))+1)%2==0;
        }
        return ans;
    }
};