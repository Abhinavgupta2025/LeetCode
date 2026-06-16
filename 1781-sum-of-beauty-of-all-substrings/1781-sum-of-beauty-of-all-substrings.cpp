class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            int mx = 0;
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                mx = max(mx,freq[s[j]-'a']);
                int mn = INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>0) mn = min(mn,freq[k]);
                }
                ans+= (mx-mn);
            }
            
        }
        return ans;
    }
};