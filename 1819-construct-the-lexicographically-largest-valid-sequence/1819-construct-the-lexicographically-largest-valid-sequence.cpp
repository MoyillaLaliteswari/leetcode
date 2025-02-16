class Solution {
public:
    bool rec(vector<int>&res,vector<bool>&used,int n,int index){
        while(index<res.size() and res[index]!=0){
            index++;
        }
        if(index==res.size()){
            return true;
        }
        for(int i=n;i>=1;i--){
            if(used[i])continue;
            if(i==1){
                res[index]=1;
                used[1]=true;
                if(rec(res,used,n,index+1))return true;
                res[index]=0;
                used[1]=false;
            }
            else if(index+i<res.size() && res[index+i]==0){
                res[index]=i;
                res[index+i]=i;
                used[i]=true;
                if(rec(res,used,n,index+1)) return true;
                res[index]=0;
                res[index+i]=0;
                used[i]=false;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1,0);
        vector<bool>used(n+1,false);
        rec(res,used,n,0);
        return res;  
    }
};