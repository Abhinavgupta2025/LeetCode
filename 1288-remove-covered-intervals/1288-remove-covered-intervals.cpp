class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
             if(a[0]==b[0]){
                return a[1]>b[1];
             }
             return a[0]<b[0];
         });
         vector<vector<int>> ans;
         for(auto it : intervals){
             if(ans.size()==0 || (it[0]>=ans.back()[0] && it[1]>ans.back()[1])) ans.push_back(it);
             else{
                ans.back()[0] = min(ans.back()[0],it[0]);
                ans.back()[1] = max(ans.back()[1],it[1]);
             }
         }
         
         return ans.size();
    }
};