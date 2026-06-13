class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
            int n = words.size();
            string s = "";
            for(int i=0;i<n;i++){
                string word = words[i];
                int sum = 0;
                for(int j=0;j<word.length();j++){
                    char ch = word[j];
                    sum += weights[ch-'a'];
                }
                 s += char('z' - (sum % 26));
            }
        return s;
    }
};