class Solution {
public:
    long long sumAndMultiply(int n) {
            string s = to_string(n);
            int c = s.length();
             long long count = 0;
             long long num = 0;
            for(int i=0;i<c;i++){
                if(s[i]!=('0')){
                    count += s[i] - '0';
                    num *= 10;
                    num += s[i] - '0';
                }
            }
            return count*num;
    }
};