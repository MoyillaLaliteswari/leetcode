class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>su;
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                su.push_back(sum);
            }
        }
        sort(su.begin(),su.end());
        long long sum=0;
        for(int i=left-1;i<right;i++){
            sum+=su[i];
        }
        return static_cast<int>(sum%1000000007);
    }
};