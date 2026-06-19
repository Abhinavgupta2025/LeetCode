class Solution {
public: 
    void check(int idx,vector<int>& temp,vector<int>& nums,vector<vector<int>>& ans){
            ans.push_back(temp);
            for(int i=idx;i<nums.size();i++){
                if(i>idx && nums[i]==nums[i-1]) continue;
                temp.push_back(nums[i]);
                check(i+1,temp,nums,ans);
                temp.pop_back();
            }
            return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            vector<int> temp;
            check(0,temp,nums,ans);
            return ans;

    }
};