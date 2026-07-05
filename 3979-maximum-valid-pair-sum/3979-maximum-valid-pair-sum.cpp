class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> nge(n,0);
            long long mx = nums[n-1];
            for(int i=n-1;i>=0;i--){
                mx = max(mx,(long long)nums[i]);
                nge[i] = mx;
            }
            mx = 0;
            for(int i=0;i<n;i++){
                if(i+k<n){
                    mx = max(mx,1LL*nums[i]+nge[i+k]);
                }
            }
            return (int)mx;
    }
};