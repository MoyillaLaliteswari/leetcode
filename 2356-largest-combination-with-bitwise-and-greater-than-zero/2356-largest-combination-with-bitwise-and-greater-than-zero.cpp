class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int n:candidates){
                if(n&(1<<i)){
                    cnt++;
                }
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};