class Solution {
public:
    int minimumCost(vector<int>& cost) {
            int n = cost.size();
            sort(cost.begin(),cost.end());
            int count = 1;
            int ans = 0;
            for(int i=n-1;i>=0;i--){
                if(count==3){
                    count = 1;
                    continue;
                }
                ans+= cost[i];
                count++;
            }
            return ans;
    }
};