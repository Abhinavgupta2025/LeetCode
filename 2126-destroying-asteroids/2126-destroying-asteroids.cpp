class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
            int n = asteroids.size();
            long long count = mass;
            sort(asteroids.begin(),asteroids.end());
            for(int i=0;i<n;i++){
                if(asteroids[i]<=count){
                    count+= asteroids[i];
                }
                else return false;
            }
            return true;
    }
};