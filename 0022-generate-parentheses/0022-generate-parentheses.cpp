class Solution {
public:
    void check(int in,int out,string s,vector<string>& ans,int n){
            if(s.length()==2*n){
                if(in == out){
                    ans.push_back(s);
                }
                return;
            } 
            if(in>out){
                check(in,out+1,s+')',ans,n);
            }
            check(in+1,out,s+'(',ans,n);
            return;
    }
    vector<string> generateParenthesis(int n) {
            vector<string> ans;
            check(0,0,"",ans,n);
            return ans;
    }
};