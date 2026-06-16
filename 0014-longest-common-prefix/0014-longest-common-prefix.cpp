class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
            int n = arr.size();
            sort(arr.begin(),arr.end());
            string ans = arr[0];
            for(int i=1;i<n;i++){
                string s = arr[i];
                for(int i=0;i<s.length();i++){
                    if(s[i]!=ans[i]){
                        ans = ans.substr(0,i);
                        break;
                    }
                }
            }
            return ans;
    }
};