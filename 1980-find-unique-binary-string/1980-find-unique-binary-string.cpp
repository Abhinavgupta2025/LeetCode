class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            int size = pow(2,n);
            vector<int> check(size,0);
            for(auto it : nums){
                int x = stoi(it,nullptr,2);
                check[x]++;
            }
            for(int i=0;i<size;i++){
                if(check[i]==0){
                    string ans = bitset<32>(i).to_string();
                    ans = ans.substr(32-n);
                    return ans;
                }
            }
            return string(n,'0');
    }
};