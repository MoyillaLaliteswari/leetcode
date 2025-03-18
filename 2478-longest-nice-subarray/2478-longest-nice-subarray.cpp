class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int m=1;
        int left=0;
        int bits=0;
        for(int i=0;i<n;i++){
            while((bits & nums[i])!=0){
                bits ^=nums[left];
                left++;
            }
            bits |=nums[i];
            m=max(m,i-left+1);
        }
        return m;
    }
};