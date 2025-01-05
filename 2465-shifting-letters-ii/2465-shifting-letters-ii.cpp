class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diffArr(n,0);
        for(auto shift:shifts){
            if(shift[2]==1){
                diffArr[shift[0]]++;
                if(shift[1]+1<n){
                    diffArr[shift[1]+1]--;
                }
            }else{
                diffArr[shift[0]]--;
                if(shift[1]+1<n){
                    diffArr[shift[1]+1]++;
                }
            }
        }
        string res(n,' ');
        int ns=0;
        for(int i=0;i<n;i++){
            ns=(ns+diffArr[i])%26;
            if(ns<0){
                ns+=26;
            }
            res[i]='a'+(s[i]-'a'+ns)%26;
        }
        return res;
    }
};