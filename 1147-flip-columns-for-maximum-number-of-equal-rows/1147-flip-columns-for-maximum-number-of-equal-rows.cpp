class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;
        for(const auto& row : matrix){
            string key;
            bool flip=row[0]==1;
            for(int num:row){
                key+=flip ? ('0'+(1-num)) : ('0'+num);
            }
            mp[key]++;
        }
        int m=0;
        for(const auto &i:mp){
            m=max(m,i.second);
        }
        return m;
    }
};