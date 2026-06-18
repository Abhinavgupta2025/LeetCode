class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(),s.end());
        int left = 0;
        int right = 0;
        int start = 0;
        while(right<n){
            while(right<n && s[right]==32){
                right++;
            }
            if(right == n) break;
            while(right<n && s[right]!=32){
                s[left++] = s[right++];
            }
            reverse(s.begin()+start,s.begin()+left);
            s[left++] = ' ';
            start = left;
            
        }
        s.resize(left-1);
        
        return s;
    }
};