class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>snums(n);
        for(int i=0;i<n;i++){
            snums[i]={nums[i],i};
        }
        sort(snums.begin(),snums.end());
        long long score=0;
        for(int i=0;i<n;i++){
            int num=snums[i].first;
            int idx=snums[i].second;
            if(nums[idx]!=-1){
                score+=num;
                nums[idx]=-1;
                if(idx>0){
                    nums[idx-1]=-1;
                }
                if(idx<n-1){
                    nums[idx+1]=-1;
                }
            }
        }
        return score;
    }
};