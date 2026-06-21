class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
            int n = s.size();
            vector<int> diff(n,0);
            for(auto it : shifts){
                int x = it[0];
                int y = it[1];
                int dir = it[2];
                int val = 1;
                if(dir==0)  val = -1;
                diff[x] += val;
                if(y+1<n)diff[y+1] -=val;
            }
            for(int i=1;i<n;i++){
                diff[i] = diff[i] + diff[i-1];
            }

            for(int i=0;i<n;i++){
                int val = diff[i];
                val = val%26;
                if(val<0){
                    val +=26;
                }
                s[i] =(((s[i]-'a')+val)%26) + 'a';
            }
            return s;
    }
};