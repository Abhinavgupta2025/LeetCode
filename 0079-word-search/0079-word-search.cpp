class Solution {
public:
    bool check(int idx,int row,int col,string word,vector<vector<int>>& vis,vector<vector<char>>& board){
            if(row<0 || col<0 || row>=board.size() || col>=board[0].size()) return false;
            if(vis[row][col]) return false;
            if(idx<word.size() && board[row][col] != word[idx]) return false;
            if(idx==word.size()-1) return true;
            vis[row][col] = 1;
            bool checkAns = check(idx+1,row+1,col,word,vis,board)||
                         check(idx+1,row-1,col,word,vis,board)||
                         check(idx+1,row,col+1,word,vis,board)||
                         check(idx+1,row,col-1,word,vis,board);
            vis[row][col] = 0;
            return checkAns;
    }
    bool exist(vector<vector<char>>& board, string word) {
            int n = board.size();
            int m = board[0].size();
            vector<vector<int>> vis(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(check(0,i,j,word,vis,board)) return true;
                }
            }
            return false;
    }   
};