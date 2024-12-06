class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int>mp;
        for(int i=0;i<banned.size();i++){
            if(banned[i]<=n){
                mp[banned[i]]++;
            }
        }
        int s=0,cnt=0;
        for(int i=1;i<=n;i++){
            if((mp.find(i)==mp.end()) and ((s+i)<=maxSum)){
                s=s+i;
                cnt++;
            }
        }
        return cnt;
    }
};