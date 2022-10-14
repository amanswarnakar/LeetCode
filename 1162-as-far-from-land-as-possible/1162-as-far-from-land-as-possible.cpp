class Solution {
public:
    bool check(int m, int n, int r, int c){
      if(r < 0 or r >= m or c < 0 or c >= n) return false;
      return true;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int maxDistance(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size();
      vector<vector<int>> dp(m, vector<int>(n, -1));
      queue<pair<int, int>> q;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(v[i][j] == 1){
            q.push({i, j});
            dp[i][j] = 0;
          }
        }
      }
      while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        int dis = dp[r][c];
        q.pop();
        for(int i = 0; i < 4; i++){
          int x = r + dx[i], y = c + dy[i];
          if(check(m, n, x, y) and dp[x][y] == -1){
            dp[x][y] = dis + 1;
            q.push({x, y});
          }
        }
        // if(check(m, n, r+1, c) and dp[r+1][c] == -1){
        //   dp[r+1][c] = dis + 1;
        //   q.push({r+1, c});
        // }
        // if(check(m, n, r-1, c) and dp[r-1][c] == -1){
        //   dp[r-1][c] = dis + 1;
        //   q.push({r-1, c});
        // }
        // if(check(m, n, r, c+1) and dp[r][c+1] == -1){
        //   dp[r][c+1] = dis + 1;
        //   q.push({r, c+1});
        // }
        // if(check(m, n, r, c-1) and dp[r][c-1] == -1){
        //   dp[r][c-1] = dis + 1;
        //   q.push({r, c-1});
        // }
      }
      int ans = -1;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          ans = max(ans, dp[i][j]);
        }
      }
      return !ans ? -1 : ans;
    }
};