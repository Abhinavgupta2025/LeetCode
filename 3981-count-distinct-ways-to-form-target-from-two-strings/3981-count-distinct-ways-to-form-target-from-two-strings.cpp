class Solution {
public:
    int n,m,o;
    int dp[101][101][101][2][2];
    const int mod = 1e9+7;
    int check(int idx1,int idx2,int idx3,bool flag1,bool flag2,
          string& word1,string& word2,string& target){
         if(idx3==o){
            if(flag1 && flag2) return 1;
            return 0;
         }
        if (dp[idx1][idx2][idx3][flag1][flag2]!=-1) return dp[idx1][idx2][idx3][flag1][flag2];
         int take1 = 0;
         for(int i=idx1;i<n;i++){
            if(target[idx3]==word1[i]){
                take1 = (take1 +  check(i+1,idx2,idx3+1,true,flag2,word1,word2,target))%mod;
            }
         }
         int take2 = 0;
         for(int i=idx2;i<m;i++){
            if(target[idx3]==word2[i]){
                take2 = (take2+check(idx1,i+1,idx3+1,flag1,true,word1,word2,target))%mod;
            }
         }
         return dp[idx1][idx2][idx3][flag1][flag2] = ((take1+take2)%mod);

    }
    int interleaveCharacters(string word1, string word2, string target) {
            n = word1.size();
            m = word2.size();
            o = target.size();
            memset(dp,-1,sizeof(dp));
            return check(0,0,0,false,false,word1,word2,target);
    }
};