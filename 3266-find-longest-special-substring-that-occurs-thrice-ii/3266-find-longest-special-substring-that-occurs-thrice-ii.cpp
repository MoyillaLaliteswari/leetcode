class Solution {
public:
int &getMin(int &a,int &b,int &c){
    if(a<=b and a<=c)return a;
    if(b<=a and b<=c)return b;
    return c;
}
    int maximumLength(string s) {
        int n=s.size();
        vector<vector<int>>freq(26,vector<int>(3,-1));
        char visited='*';
        int len=0;
        for(char& curr:s){
            int idx=curr-'a';
            len=curr==visited ? len+1 :1;
            visited=curr;
            int &mini=getMin(freq[idx][0],freq[idx][1],freq[idx][2]);
            if(len>mini){
                mini=len;
            }
        }
        int m=-1;
        for(int i=0;i<26;i++){
            m=max(m,(min({freq[i][0],freq[i][1],freq[i][2]})));
        }
        return m;
    }
};