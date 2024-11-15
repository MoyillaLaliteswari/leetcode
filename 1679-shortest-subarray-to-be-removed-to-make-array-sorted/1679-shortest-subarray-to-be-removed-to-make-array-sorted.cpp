class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        while(r>0 and arr[r]>=arr[r-1]){
            r--;
        }
        int s=r;
        while(l<r){
            while(r<arr.size() and arr[l]>arr[r]){
                r++;
            }
            s=min(s,r-l-1);
            l++;
            if(arr[l-1]>arr[l]){
                break;
            }
        }
        return s;
    }
};