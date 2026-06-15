class Solution {
public:
    int check(int mid,int threshold,vector<int>& nums){
            int n = nums.size();
            int count = 0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid) count += 1;
                else count += ceil((double)nums[i]/mid);
            }
            return count <=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
            int n = nums.size();
            int low = 1;
            int mx = nums[0];
            for(int i=1;i<n;i++){
                mx = max(mx,nums[i]);
            }
            int high = mx;
            int ans = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(check(mid,threshold,nums)){
                    ans = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            return ans;
    }
};