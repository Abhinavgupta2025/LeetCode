class Solution {
public:
    bool check(int mid,vector<int>& nums,vector<vector<int>>& queries){
            int n = nums.size();
            vector<int> diff(n,0);
            for(int i=0;i<mid;i++){
                int left = queries[i][0];
                int right = queries[i][1];
                int val = queries[i][2];
                diff[left] -= val;
                if(right+1<n) diff[right+1] += val;
            }
            for(int i=1;i<n;i++){
                diff[i] += diff[i-1];
            }
            for(int i=0;i<n;i++){
                if(nums[i] + diff[i]>0) return false;
            }
            return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            int low = 0;
            int high = queries.size();
            int ans = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(check(mid,nums,queries)){
                    ans = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            return ans;
    }
};