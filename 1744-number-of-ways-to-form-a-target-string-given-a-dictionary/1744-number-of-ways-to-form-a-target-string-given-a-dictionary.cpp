class Solution {
public:
    long getWords(vector<string>&words,string &target,int wordsIndex,int targetIndex,vector<vector<int>>&dp,vector<vector<int>>& charFreq){
        if(targetIndex==target.size()) return 1;
        if(wordsIndex==words[0].size() || words[0].size()-wordsIndex<target.size()-targetIndex) return 0;
        if(dp[wordsIndex][targetIndex] !=-1) return dp[wordsIndex][targetIndex];
        long countWays=0;
        int curPos=target[targetIndex]-'a';
        countWays+=getWords(words,target,wordsIndex+1,targetIndex,dp,charFreq);
        countWays+=charFreq[wordsIndex][curPos]*getWords(words,target,wordsIndex+1,targetIndex+1,dp,charFreq);
        return dp[wordsIndex][targetIndex]=countWays%1000000007;
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>>dp(words[0].size(),vector<int>(target.size(),-1));
        vector<vector<int>>charFreq(words[0].size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[0].size();j++){
                int chara=words[i][j]-'a';
                charFreq[j][chara]++;
            }
        }
        return getWords(words,target,0,0,dp,charFreq);
    }
};