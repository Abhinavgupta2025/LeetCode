class Solution {
public:
    bool check(long long mid,int dy,vector<int> days){
         int n = days.size();
         long long idx = 0;
         long long temp = mid;
         long long count = 1;
         while(idx<n){
            if(temp>=(long long)days[idx]){
                temp-=(long long)days[idx];
                idx++;
            }
            else{
                temp = mid;
                temp-=(long long)days[idx];
                count++;
                idx++;
            }
         }
         return count<=dy;
    }
    int shipWithinDays(vector<int>& weights, int days) {
            int n = weights.size();
            int mn = 0;
            long long sum = accumulate(weights.begin(),weights.end(),0LL);
            for(int i=0;i<n;i++){
                mn = max(weights[i],mn);
            }
            long long low = mn;
            long long high = sum;
            long long ans = -1;
            while(low<=high){
                long long mid = low + (high-low)/2;
                if(check(mid,days,weights)){
                    ans = mid;
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            return ans;
    }
};