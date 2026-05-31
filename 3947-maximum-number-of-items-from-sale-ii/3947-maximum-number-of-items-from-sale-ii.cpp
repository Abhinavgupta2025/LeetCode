class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
            int n = items.size();
            int mx = 0;
            int mn = 1e9;
            for(auto it : items){
                mx = max(mx,it[0]);
                mn = min(mn,it[1]);
            }
            vector<int> freq(mx+1,0);
            for(auto it : items){
                freq[it[0]]++;
            }
            vector<int> factors(mx+1,0);
            for(int i=1;i<=mx;i++){//to cakculate the frequsing sieve of eratosthenes
                    if(freq[i]==0) continue;
                for(int j=i;j<=mx;j+=i){
                    factors[i] += freq[j];
                }
            }

            vector<pair<long long,long long>> v;
            for(auto it : items){
                long long factor = it[0];
                long long price  = it[1];
                long long count  = factors[factor]-1;
                if(count>0 && price<2*mn) v.push_back({price,count});
            }
            sort(v.begin(),v.end());
            long long ans = 0;
            int left = budget;
            for(auto it : v){
                int price = it.first;
                int count = it.second;
                int l = min(count,left/price);//us price mai kitna milega
                ans += 2*l;
                left -= l*price;
                if(l<count) break;
            }
            ans += left/mn;
            return (int)ans;


    }
};