class Solution {
public:
    int minOperations(string s1, string s2) {
            int n = s1.length();
            if(s1==s2) return 0;
            if(n==1 && s1[0]=='1') return -1;
            string s3 = s1;
            int count = 0;
            for(int i=0;i<n;i++){
                if(s1[i]==s2[i]) continue;
                if(s1[i]=='0' && s2[i]=='1'){
                    count++;
                    s1[i] = '1';
                }
                else if(s1[i]=='1' && s2[i]=='0'){
                    if(i==0 && i+1<n){
                        if(s1[i+1]=='1'){
                            s1[i+1] = '0';
                            count++;
                        }
                        else if(s1[i+1]=='0') count +=2;
                    }
                    else if(i>0 && i<n-1){
                        if(s1[i+1]=='1'){
                            s1[i+1] = '0';
                            count++;
                        }
                        else count +=2;
                    }
                    else if(i==n-1){
                        count+=2;
                    }
                }
                
            }
            return count;
    }
};