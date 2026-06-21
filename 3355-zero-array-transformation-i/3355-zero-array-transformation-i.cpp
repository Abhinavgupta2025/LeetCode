class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
                int n = nums.size();
                vector<int> diff(n,0);
                for(auto it : queries){
                    int x = it[0];
                    int y = it[1];
                    diff[x] -=1;
                    if(y+1<n) diff[y+1] += 1;
                }
                for(int i=1;i<n;i++){
                    diff[i] += diff[i-1];
                }
                for(int i=0;i<n;i++){
                    if(nums[i]+diff[i]>0) return false;
                }
                return true;
    }
};