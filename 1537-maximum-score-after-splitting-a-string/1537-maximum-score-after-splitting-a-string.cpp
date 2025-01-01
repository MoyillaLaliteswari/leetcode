class Solution {
public:
    int maxScore(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            int cur=0;
            for(int j=0;j<=i;j++){
                if(s[j]=='0'){
                    cur++;
                }
            }
            for(int j=i+1;j<s.size();j++){
                if(s[j]=='1'){
                    cur++;
                }
            }
            sum=max(sum,cur);
        }
        return sum;
    }
};