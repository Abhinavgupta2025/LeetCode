class Solution {
public:
    int minLights(vector<int>& lights) {
            int n = lights.size();
            vector<int> diff(n,0);
            for(int i=0;i<n;i++){
                if(lights[i]!=0){
                    int leftRange = max(0,i-lights[i]);
                    int rightRange = i + lights[i];
                    diff[leftRange] += 1;
                    if(rightRange+1<n) diff[rightRange+1]-=1;
                }
            }
            for(int i=1;i<n;i++){
                diff[i] = diff[i] + diff[i-1];
            }
            int ans = 0;
            for(int i=0;i<n;i++){
                if(diff[i]==0 && lights[i]==0){
                    ans++;
                    if(i+1<n) diff[i+1] = 1;
                    if(i+2<n) diff[i+2] = 1;
                }
            }
            return ans;
    }
};