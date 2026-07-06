class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        
      
        int ans = tickets[k];
        int kstickets = tickets[k];

        
        for(int i = 0; i < k; i++){
            ans += min(tickets[i], kstickets);
        }
        
        
        for(int i = k + 1; i < n; i++){
            ans += min(tickets[i], kstickets - 1);
        }

        return ans;
    }
};