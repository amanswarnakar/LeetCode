class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
      int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };
      int m = grid.size(), n = grid[0].size(), ans = 0;
      vector<vector<int>> remains(m, vector<int>(n, INT_MIN));
      queue<vector<int>> q;
      q.emplace(vector<int>{0, 0, k});
      remains[0][0] = k;
      while (!q.empty()) {
        for (int it = q.size(); it > 0; it--) {
          auto top = q.front(); q.pop();
          int r = top[0], c = top[1];
          if (r == m - 1 && c == n - 1) return ans;
          for (int i = 0; i < 4; i++) {
            int x = r + dx[i], y = c + dy[i];
            if(min(x, y) >= 0 and x < m and y < n){
              int remain = top[2] - grid[x][y];
              if(remain >= 0 && remains[x][y] < remain) {
                q.emplace(vector<int>{x, y, remain});
                remains[x][y] = remain;
              }
            }
          }
        }
        ans++;
      }
      return -1;
    }
};


