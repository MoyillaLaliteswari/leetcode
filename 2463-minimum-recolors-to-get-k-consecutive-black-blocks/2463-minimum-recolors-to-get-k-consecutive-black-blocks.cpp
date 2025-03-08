class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt=0,i=0,j=0;
        int mini=INT_MAX;
        while(i<blocks.size()){
            if(i-k>=0 and blocks[i-k]=='B'){
                cnt--;
            }
            if(blocks[i]=='B'){
                cnt++;
            }
            mini=min(mini,k-cnt);
            i++;
        }
        return mini;
    }
};