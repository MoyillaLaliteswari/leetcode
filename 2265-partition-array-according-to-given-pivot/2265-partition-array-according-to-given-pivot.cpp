class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> v1(nums.size());
    int index1 = 0, cnt = 0;

    for (int num : nums) {
        if (num < pivot) {
            v1[index1++] = num;
        } else if (num == pivot) {
            cnt++;
        }
    }

    while (cnt--) {
        v1[index1++] = pivot;
    }
    for (int num : nums) {
        if (num > pivot) {
            v1[index1++] = num;
        }
    }

    return v1;
}

};