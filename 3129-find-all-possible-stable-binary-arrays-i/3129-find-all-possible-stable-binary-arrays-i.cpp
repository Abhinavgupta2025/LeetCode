class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        int MOD = 1e9 + 7;

        // dp[z][o][prev][cnt]
        static long long dp[201][201][2][201];

        memset(dp, 0, sizeof(dp));

        // Starting with 0
        if(zero > 0)
            dp[1][0][0][1] = 1;

        // Starting with 1
        if(one > 0)
            dp[0][1][1][1] = 1;

        for(int z = 0; z <= zero; z++){

            for(int o = 0; o <= one; o++){

                for(int prev = 0; prev < 2; prev++){

                    for(int cnt = 1; cnt <= limit; cnt++){

                        long long ways = dp[z][o][prev][cnt];

                        if(ways == 0) continue;

                        // place 0
                        if(z < zero){

                            int newCnt =
                                (prev == 0) ? cnt + 1 : 1;

                            if(newCnt <= limit){

                                dp[z+1][o][0][newCnt] += ways;
                                dp[z+1][o][0][newCnt] %= MOD;
                            }
                        }

                        // place 1
                        if(o < one){

                            int newCnt =
                                (prev == 1) ? cnt + 1 : 1;

                            if(newCnt <= limit){

                                dp[z][o+1][1][newCnt] += ways;
                                dp[z][o+1][1][newCnt] %= MOD;
                            }
                        }
                    }
                }
            }
        }

        long long ans = 0;

        for(int cnt = 1; cnt <= limit; cnt++){

            ans += dp[zero][one][0][cnt];
            ans %= MOD;

            ans += dp[zero][one][1][cnt];
            ans %= MOD;
        }

        return ans;
    }
};