class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>prefixSum(words.size());
        int cnt=0;
        int i=0;
        for(auto& word:words){
            if((word[0]=='a' or word[0]=='e' or word[0]=='i' or word[0]=='o' or word[0]=='u') and (word[word.size()-1]=='a' or word[word.size()-1]=='e' or word[word.size()-1]=='i' or word[word.size()-1]=='o' or word[word.size()-1]=='u')){
                cnt++;
            }
            prefixSum[i]=cnt;
            i++;
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            vector<int>cur=queries[i];
            ans[i]=prefixSum[cur[1]]-
            (cur[0]==0?0:prefixSum[cur[0]-1]);
        }
        return ans;
    }
};