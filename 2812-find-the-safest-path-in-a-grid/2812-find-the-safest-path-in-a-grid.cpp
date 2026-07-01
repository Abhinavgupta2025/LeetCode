class Solution {
public:
    bool isValid(int r, int c, int n) {
        return (r >= 0 && c >= 0 && r < n && c < n);
    }

    // Step 1: Compute distance of every cell from nearest thief
    vector<vector<int>> computeDist(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Push all thieves
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(isValid(nr, nc, n) && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }

    // Step 2: Check if path exists with safeness >= mid
    bool canReach(int mid, vector<vector<int>>& dist) {
        int n = dist.size();

        if(dist[0][0] < mid) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r == n-1 && c == n-1) return true;

            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(isValid(nr, nc, n) &&
                   !vis[nr][nc] &&
                   dist[nr][nc] >= mid) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist = computeDist(grid);

        int low = 0;
        int high = 2 * n;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canReach(mid, dist)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};