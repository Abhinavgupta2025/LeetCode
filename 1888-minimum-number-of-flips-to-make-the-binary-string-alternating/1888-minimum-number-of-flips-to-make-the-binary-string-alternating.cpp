class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s = (s+s);
        string s1 = s;
        string s2 = s;
        for(int i=0;i<2*n;i++){
            s1[i] = (i%2==0)?'1':'0';
            s2[i] = (i%2==0)?'0':'1';
        }
        int i=0;
        int j=0;
        int flips1 = 0;
        int flips2 = 0;
        int ans = INT_MAX;
        while(j<2*n){
            if(s[j]!=s1[j]){
                flips1++;
            }
            if(s[j]!=s2[j]){
                flips2++;
            }
            if(j-i+1>n){
                if(s[i]!=s1[i]){
                    flips1--;
                }
                if(s[i]!=s2[i]){
                    flips2--;
                }
                i++;
            }
            if(j-i+1==n){
                ans = min({ans,flips1,flips2});
            }
            j++;
        }
        return ans;
    }
};