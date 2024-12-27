class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>v(n);
        v[0]=values[0];
        int maxi=0;
        for(int i=1;i<n;i++){
            int curr=values[i]-i;
            maxi=max(maxi,v[i-1]+curr);
            int curl=values[i]+i;
            v[i]=max(v[i-1],curl);
        }
        return maxi;
    }
};