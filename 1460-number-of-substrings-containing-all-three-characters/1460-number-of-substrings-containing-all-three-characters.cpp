class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int left=0;
        unordered_map<char,int>ch={{'a',0},{'b',0},{'c',0}};
        for(int right=0;right<s.length();right++){
            ch[s[right]]++;
            while(ch['a']>0 and ch['b']>0 and ch['c']>0){
                cnt+=s.length()-right;
                ch[s[left]]--;
                left++;
            }
        }
        return cnt;
    }
};