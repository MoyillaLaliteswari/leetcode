class Solution {
public:
    bool isPrime(int num){
        if(num<=1) return false;
        if(num==2 || num==3) return true;
        if(num%2==0 || num%3==0) return false;
        for(int i=5;i*i<=num;i+=6){
            if(num%i==0 || num%(i+2)==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int m=INT_MAX;
        int num1=-1;
        int num2=-1,prev=-1;
        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                if(prev!=-1 and i-prev<m){
                    m=i-prev;
                    num1=prev;
                    num2=i;
                }
                prev=i;
            }
            
        }
        if(num1==-1) return {-1,-1};
        return {num1,num2};
    }
};