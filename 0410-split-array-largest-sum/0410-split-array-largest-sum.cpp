class Solution {
public:
    bool check(long long mid,int k,vector<int>& nums){
        int n = nums.size();
        long long temp = mid;
        long long count = 1;
        for(int i=0;i<n;i++){
            if(temp>=(long long)nums[i]){
                temp-=(long long)nums[i];
            }
            else{
                temp = mid;
                temp-=(long long)nums[i];
                count++;
            }
        }

        return count<=(long long)k;
    }
    int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            long long low = *max_element(nums.begin(),nums.end());
            long long high = accumulate(nums.begin(),nums.end(),0LL);
            int ans = -1;
            while(low<=high){
                long long mid = low + (high-low)/2;

                if(check(mid,k,nums)){
                    ans = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            return ans;
    }
};