class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size();
      // queue<pair<int, int>> q;
      vector<vector<int>> ans(m, vector<int>(n, 0));
      vector<vector<int>> vis(m, vector<int>(n, 0));
      queue<pair<pair<int, int>, int>> q;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(v[i][j] == 0){
            q.push({{i, j}, 0});
            vis[i][j] = 1;
          }
        }
      }
      int dx[4] = {1, 0, -1, 0};
      int dy[4] = {0, 1, 0, -1};
      while(!q.empty()){
        int r = q.front().first.first, c = q.front().first.second;
        ans[r][c] = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
          int x = r + dx[i], y = c + dy[i];
          if(x >= 0 and x < m and y >= 0 and y < n and vis[x][y] == 0){
            q.push({{x, y}, ans[r][c] + 1});
            vis[x][y] = 1;
          }
        }
      }
      return ans;
    }
};