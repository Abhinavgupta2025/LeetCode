class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
            int n = s.length();
            int m = t.length();
            if(n>m) return false;
            if(s==t) return true;
            vector<int> left(n,-1);
            vector<int> right(m,-1);
            int p = 0;
            for(int i=0;i<n;i++){
                while(p<m && s[i]!=t[p])p++;
                if(p==m) break;
                left[i] = p++;
            }
            if(left[n-1]!=-1) return true;
            p = m-1;
            for(int i=n-1;i>=0;i--){
                while(p>=0 && s[i]!=t[p]) p--;
                if(p==-1) break;
                right[i] = p--;
            }
            for(int i=0;i<n;i++){
                if((i==0 || left[i-1]!=-1) && (i==n-1||right[i+1]!=-1)){
                    int l = (i==0)?-1:left[i-1];
                    int r = i==n-1?m:right[i+1];
                    if(l+1<r) return true;
                }
            }
            return false;
    }
};