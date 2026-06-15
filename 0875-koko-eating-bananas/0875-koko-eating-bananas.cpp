class Solution {
public: 
    bool check(int speed,vector<int>& piles,int h){
         int n = piles.size();
         long long count = 0;
         for(int i=0;i<n;i++){
            if(piles[i]<=speed) count += 1;
            else if(piles[i]%speed==0) count += piles[i]/speed;
            else count += (piles[i]/speed) + 1;
         }
         return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int mx = *max_element(piles.begin(),piles.end());
            int low = 1;
            int high = mx;
            int ans = -1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(check(mid,piles,h)){
                    ans = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            return ans;
    }
};