class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mx = 0;
        vector<pair<int,int>> ans;

        for (auto it : nums) {
            string s = to_string(it);
            sort(s.begin(), s.end());

            int range = (s[s.length() - 1] - '0') - (s[0] - '0');

            ans.push_back({range, it});
            mx = max(mx, range);
        }

        long long sum = 0;

        for (auto it : ans) {
            if (it.first == mx)
                sum += it.second;
        }

        return sum;
    }
};