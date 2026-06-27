class Solution {
public:
    int maximumLength(vector<int>& nums) {
            int n = nums.size();
            
            map<long long,int> mp;
            for(int i=0;i<n;i++){
                1LL*mp[nums[i]]++;
            }
            int ans = 1;
            if(mp[1] % 2 == 0) ans = max(ans, mp[1] - 1);
            else ans = max(ans, mp[1]);
            for(auto it : mp){
                long long val = it.first;
                int freq = it.second;
                int count = 0;
                if(val==1) continue;
                while(mp.find(val)!=mp.end() && count<n){
                    long long nxt = 1LL*val*val;
                    if(mp[val]>=2 && mp.find(nxt)!=mp.end()){
                        count+=2;
                        val = nxt;
                        ans = max(ans,count);
                    }
                    else{
                        count+=1;
                        ans = max(ans,count);
                        break;
                    }
                }
            }
             return ans;
    }
};