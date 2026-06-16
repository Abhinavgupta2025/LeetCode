class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int idx = 0;
        long long ans = 0;
        while(idx<n && s[idx]==32){
            idx++;
        }
        if(idx==n) return 0;
        s = s.substr(idx);
        n = s.length();
        idx = 0;
        int sign = 1;
        if(s[0]=='+') idx++;
        if(s[0]=='-') {
            sign = -1;
            idx++;
            }
        while(idx<n){
            if(s[idx]==32 || !isdigit(s[idx])){
                break;
            }
            ans = (1LL*ans*10) + (s[idx]-'0');
            if(sign == -1 && sign*ans<=INT_MIN) return INT_MIN;
            if(sign == 1 && ans>=INT_MAX) return INT_MAX;
            idx++;
        } 
        return sign*ans;
    }
};