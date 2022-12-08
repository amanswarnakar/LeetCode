class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
      queue<pair<int, int>> q;
      int m = grid.size(), n = grid[0].size();
      vector<vector<bool>> vis(m, vector<bool>(n, false));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(grid[i][j] == 2){
            q.push({i, j});
            vis[i][j] = true;
          } 
          if(grid[i][j] == 0) vis[i][j] = true;
        }
      }
      int ans = 0;
      while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
          auto qf = q.front(); q.pop();
          int r = qf.first, c = qf.second;
          grid[r][c] = 2;
          for(int i = 0; i < 4; i++){
            int x = r + dx[i], y = c + dy[i];
            if(min(x, y) >= 0 and x < m and y < n and !vis[x][y] and grid[x][y] == 1){
              q.push({x, y});
              vis[x][y] = true;
            }
          }
        }
        if(!q.empty()) ans++;
      }
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
          if(grid[i][j] == 1) return -1;
      }
      return ans;
    }
};