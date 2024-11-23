class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        for(int row=0;row<n;row++){
            int rev=m-1;
            for(int col=m-1;col>=0;col--){
                if(box[row][col]=='*'){
                    rev=col-1;
                }
                else if(box[row][col]=='#'){
                    box[row][col]='.';
                    box[row][rev]='#';
                    rev--;
                }
            }
        }
        vector<vector<char>>v(m,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[j][n-i-1]=box[i][j];
            }
        }
        return v;
    }
};