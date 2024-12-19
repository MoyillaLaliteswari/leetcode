class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    long long cnt = 0; 
    long long s = 0;
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        s += i;         
        sum += arr[i];   
        if (s == sum) {  
            cnt++;
        }
    }
    return cnt;
}


};



