class Solution {
public:
    int getNumber(int current,int n){
        if(current*10<=n){
            return current*10;
        }
        if(current>=n){
            current=current/10;
        }
        current+=1;
        while(current%10==0){
            current=current/10;
        }
        return current;
    }
    vector<int> lexicalOrder(int n) {
        int current=1;
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(current);
            current=getNumber(current,n);
        }
        return v;
    }
};