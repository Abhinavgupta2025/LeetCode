class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            if(nums.size()==0) return 0;
            if(nums.size()==1) return 1;
            unordered_set<int> st(nums.begin(),nums.end());
            int ans = 1;
            for(int i=0;i<n;i++){
                if(st.find(nums[i]-1)==st.end()){
                    int count = 1;
                    st.erase(nums[i]);
                    while(st.find(nums[i]+count)!=st.end()){
                        st.erase(nums[i]+count);
                        count++;
                        ans = max(ans,count);
                    }
                }
            }
            return ans;
    }
};