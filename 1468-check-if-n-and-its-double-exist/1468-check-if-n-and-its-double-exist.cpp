class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int x=arr[i];
            if(x>=0 and binary_search(arr.begin()+i+1,arr.end(),2*x)) {
                return 1;
            }
            else{
                if(x%2==0 and binary_search(arr.begin()+i+1,arr.end(),x/2)){
                    return 1;
                }
            }
        }
        return 0;
    }
};