class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=0;
        int cnt=0;
        while(j<n){
            int d=nums[j]-nums[i];
            if(d<=(2*k)){
                cnt=max(cnt,j-i+1);
                j++;
            }
            else if(d>(2*k)){
                i++;
            }
        }
        return cnt;
    }
};