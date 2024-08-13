class Solution {
public:
    void alien(vector<int>&candidates,int index,vector<int>&ans,int size,int target,int Sum,vector<vector<int>>&v){
        if(index>=size && Sum!=target){
            return;
        }
        else if(Sum==target){
             v.push_back(ans);
            return;
        }
        else if(Sum>target){
            return;
        }
        ans.push_back(candidates[index]);
    alien(candidates,index+1,ans,size,target,Sum+candidates[index],v);
    while(index+1<size and candidates[index]==candidates[index+1])index++;
    ans.pop_back();
    alien(candidates,index+1,ans,size,target,Sum,v);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        alien(candidates,0,ans,candidates.size(),target,0,v);
        set<vector<int>>s(v.begin(),v.end());
        v.clear();
        for(auto it:s){
            v.push_back(it);
        }
        return v;
    }
};