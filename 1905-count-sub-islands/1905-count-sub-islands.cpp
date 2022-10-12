class Solution {
public:
    void dfs(vector<vector<int>> &p, vector<vector<int>> &q, int r, int c, int &temp){
      if(r < 0 or r == p.size() or c < 0 or c == p[0].size()) return;
      if(p[r][c] == 0 and q[r][c] == 1) temp = 0;
      if(q[r][c] == 0) return;
      q[r][c] = 0;
      dfs(p, q, r+1, c, temp);
      dfs(p, q, r-1, c, temp);
      dfs(p, q, r, c+1, temp);
      dfs(p, q, r, c-1, temp);
    }
  
    int countSubIslands(vector<vector<int>>& p, vector<vector<int>>& q) {
      int m = p.size(), n = p[0].size(), ans = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(q[i][j] == 1){
            int temp = 1;
            dfs(p, q, i, j, temp);
            ans += temp;
          } 
        }
      }
      return ans;
    }
};