class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        if(n == 1)
            return nums;

        vector<int> R;

        int l = 0; 
        int m = 0;

        for(int x : nums) {

            if(x < pivot) {
                nums[l++] = x;
            }

            else if(x > pivot) {
                R.push_back(x);
            }

            else {
                m++;
            }
        }

        for(int i = 0; i < m; i++) {
            nums[l + i] = pivot;
        }


        int idx = l + m;

        for(int x : R) {
            nums[idx++] = x;
        }

        return nums;
    }
};