class ProductOfNumbers {
public:
vector<int>nums;
int prod=1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            nums.clear();
            prod=1;
        }else{
            prod*=num;
            nums.push_back(prod);
        }
    }
    
    int getProduct(int k) {
        if(nums.size()<k) return 0;
        int ans=nums.back();
        if(nums.size()==k) return ans;
        return ans/nums[nums.size()-1-k];
    }
};

