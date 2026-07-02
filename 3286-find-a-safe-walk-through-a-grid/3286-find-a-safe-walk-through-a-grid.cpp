class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
    bool check(vector<vector<int>>& grid,int health){
            int n = grid.size();
            int m = grid[0].size();
            priority_queue<pair<int,pair<int,int>>> q;
            vector<vector<int>> vis(n,vector<int>(m,0));
            int sign = grid[0][0]==1?-1:0;
            q.push({health+sign,{0,0}});
            vis[0][0] = 1;
            while(q.size()>0){
                auto it = q.top();
                q.pop();
                int health = it.first;
                int row = it.second.first;
                int col = it.second.second;

                if(row==n-1 && col==m-1 && health>0)return true;
                if(health<=0) continue;
                int dx[4] = {0,0,1,-1};
                int dy[4] = {-1,1,0,0};
                for(int i=0;i<4;i++){
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];
                    if(isValid(nrow,ncol,n,m) && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        int val = grid[nrow][ncol]==1?-1:0;
                        q.push({health+val,{nrow,ncol}});
                    }
                }

            }
            return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
            int n = grid.size();
            int m = grid[0].size();
            return check(grid,health);
    }
};

