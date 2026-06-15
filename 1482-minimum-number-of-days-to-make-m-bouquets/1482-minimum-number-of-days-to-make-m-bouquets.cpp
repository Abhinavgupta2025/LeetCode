class Solution {
public:     
    bool check(int day,int m,int k,vector<int>& bloomDay){
         int n = bloomDay.size();
         int adj = 0;
         int bouquets = 0;
         for(int i=0;i<n;i++){
              if(bloomDay[i]<=day){
                adj++;
              }
              else adj = 0;
              if(adj==k){
                 bouquets++;
                 adj = 0;
              }
         }
         return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
         int n = bloomDay.size();
         int mx = *max_element(bloomDay.begin(),bloomDay.end());
         int low = 0;
         int high = mx;
         int ans = -1;
         while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,m,k,bloomDay)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
         }
         return ans;
    }
};