class Solution {
public:
    void check(int idx,int target,vector<int>& temp,vector<int>& candidates,vector<vector<int>>& ans){
            if(target==0){
                ans.push_back(temp);
                return;
            }
            if(target<0 || idx==candidates.size()){
                return;
            }
            temp.push_back(candidates[idx]);
            check(idx,target-candidates[idx],temp,candidates,ans);
            temp.pop_back();
            check(idx+1,target,temp,candidates,ans);
            return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            int n = candidates.size();
            vector<vector<int>> ans;
            vector<int> temp;
            check(0,target,temp,candidates,ans);
            return ans;
    }
};