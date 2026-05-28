class Solution {
public:
    int numberOfSpecialChars(string word) {
         int n = word.length();
        vector<int> arr(26,-1);
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z' && arr[word[i]-'A'] == -1){
                arr[word[i]-'A'] = i;
            }
        }
        vector<int> arr2(26,0);
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z'){
                if(arr[word[i]-'a']>i && arr[word[i]-'a']!=-1) arr2[word[i]-'a'] = 1;
                else arr2[word[i]-'a'] = -1;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(arr2[i]==1) ans++;
        }
        return ans;
    }
};