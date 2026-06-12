class Solution {
public:
    bool check(vector<int>& nums) {
            int n = nums.size();
            int idx = 1;
            while(idx<n && nums[idx]>=nums[idx-1]){
                idx++;
            }
            cout<<idx;
            if(idx == n) return true;
             if(nums[idx]>nums[0]) return false;
            idx++;
            if(idx==n-1 && nums[idx]<=nums[0]&& nums[idx]>=nums[idx-1]) return true;
            while(idx<n && nums[idx]<=nums[0] && nums[idx]>=nums[idx-1]){
                idx++;
            }
            if(idx==n) return true;
            return false;

    }
};