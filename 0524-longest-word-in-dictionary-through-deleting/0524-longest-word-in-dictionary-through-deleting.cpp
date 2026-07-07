class Solution {
public:
    bool isSubsequence(string s, string t) {
         int n = s.length();
         int m = t.length();
         if(n==0) return true;
         if(n>m) return false;
         if(s==t) return true;
         int l = 0;
         int r = 0;
         while(l<n && r<m){
            if(s[l]==t[r]){
                l++;
                r++;
            }
            else r++;
            if(l==n) return true;
         }
         return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
            int n = s.length();
            sort(dictionary.begin(),dictionary.end());
            string ans = "";
            for(auto it : dictionary){
                if(isSubsequence(it,s)){
                    if(it.length()>ans.length()){
                        ans = it;

                    }
                }
            }
            return ans;
    }
};