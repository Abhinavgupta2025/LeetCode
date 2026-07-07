class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n,-1);
        vector<int> suff(n,-1);
        pre[0] = height[0];
        suff[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            pre[i] = max(height[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = max(height[i],suff[i+1]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(height[i]<pre[i] && height[i]<suff[i]){
                count += ((min(pre[i],suff[i])) - height[i]);
            }
        }
        return count;
    }
};