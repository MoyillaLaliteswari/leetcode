class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(auto ch:logs){
            if(ch=="../"){
                if(cnt>0){
                    cnt-=1;
                }
                else{
                    continue;
                }
            }
            else if(ch=="./"){
                continue;
            }
             else{
                 cnt++;
            }
        }
        
        return cnt;
    }
};