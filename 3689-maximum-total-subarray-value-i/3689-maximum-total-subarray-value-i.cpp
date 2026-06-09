class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
            int n = nums.size();
            if(n==1) return 0;
            int  mn = 1e8;
            int  mx = 0;
            for(int i=0;i<n;i++){
                mx = max(mx,nums[i]);
                mn = min(mn,nums[i]);
            }
            long long a = 1LL * mx * k;
            long long b = 1LL * mn * k;
            return a-b;
    }
};