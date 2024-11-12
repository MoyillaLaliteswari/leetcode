class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        sort(items.begin(),items.end());
        vector<vector<int>>res={{0,0}};
        for(auto i:items){
            int price=i[0];
            int beauty=i[1];
            if(beauty>res.back()[1]){
                // res.back()[2]=price;
                res.push_back({price,beauty});
            }
        }
        vector<int>ans;
        for( int x:q){
            for(int i=res.size()-1;i>=0;i--){
                if(res[i][0]<=x){
                    ans.push_back(res[i][1]);
                    break;
                }
            }
        }
    return ans;
    }
};