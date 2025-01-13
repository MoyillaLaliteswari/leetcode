class Solution {
public:
    int minimumLength(string s) {
        int cnt=0;
        map<char,int>mp;
        for(char ch:s){
            if(mp[ch]>=2){
                cnt+=2;
                mp[ch]=0;
            }
            mp[ch]++;
        }
        return s.size()-cnt;
    }
};