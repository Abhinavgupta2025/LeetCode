class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            if(n==1) return nums;
            int ele1 = INT_MIN;
            int ele2 = INT_MIN;
            int count1 = 0;
            int count2 = 0;
            for(int i=0;i<n;i++){
                if(nums[i]==ele1){
                    count1++;
                }
                else if(nums[i]==ele2){
                    count2++;
                }
                else if(count1==0){
                    ele1 = nums[i];
                    count1 = 1;
                }
                else if(count2==0){
                    ele2 = nums[i];
                    count2 = 1;
                }
                else{
                    count1--;
                    count2--;
                }
            }
            count1 = 0;
            count2 = 0;
            for(int i=0;i<n;i++){
                if(nums[i]==ele1) count1++;
            }
            for(int i=0;i<n;i++){
                if(nums[i]==ele2) count2++;
            }
            vector<int> ans;
            if(count1>n/3) ans.push_back(ele1);
            if(ele1!=ele2 && count2>n/3) ans.push_back(ele2);
            return ans;
    }
};