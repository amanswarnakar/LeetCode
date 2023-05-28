class Solution {
public:
    int helper(int r, int c, vector<vector<int>> &v){
      set<int> s1, s2;
      int x = r, y = c;
      while(x > 0 and y > 0)
        s1.insert(v[--x][--y]);
      while(r < v.size() - 1 and c < v[0].size() - 1)
        s2.insert(v[++r][++c]);
      int res = s1.size() - s2.size();
      return abs(res);
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size();
      vector<vector<int>> res(m, vector<int>(n, 0));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          res[i][j] = helper(i, j, grid);
        }
      }
      return res;
    }
};