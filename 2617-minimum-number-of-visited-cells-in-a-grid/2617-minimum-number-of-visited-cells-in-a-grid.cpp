class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size(), ans = 1;
      vector<vector<bool>> vis(m, vector<bool>(n, false));
      queue<pair<int, int>> q;
      q.emplace(0, 0);
      vis[0][0] = true;
      while(!q.empty()){
        int sz = q.size();
        while(sz--){
          auto [r, c] = q.front(); q.pop();
          if(r == m - 1 and c == n - 1) return ans;
          if(g[r][c] == 0) continue;
          vis[r][c] = true;
          for(int i = min(g[r][c], m - r); i >= 0 ; i--){
            if(r + i < m and !vis[r + i][c]){
              q.emplace(r + i, c);
              vis[r + i][c] = true;
            }
          }
          for(int i = min(g[r][c], n - c); i >= 0 ; i--){
            if(c + i < n and !vis[r][c + i]){
              q.emplace(r, c + i);
              vis[r][c + i] = true;
            }
          }
        }
        ans++;
      }
      return -1;
    }
};