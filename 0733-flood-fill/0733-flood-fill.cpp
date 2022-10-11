class Solution {
public:
    void dfs(vector<vector<int>> &v, int r, int c, int col, int prev){
      if(r < 0 or r > v.size() - 1 or c < 0 or c > v[0].size() - 1) return;
      if(v[r][c] != prev) return;
      v[r][c] = col;
      dfs(v, r+1, c, col, prev);
      dfs(v, r-1, c, col, prev);
      dfs(v, r, c+1, col, prev);
      dfs(v, r, c-1, col, prev);
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      if(image[sr][sc] != color)
        dfs(image, sr, sc, color, image[sr][sc]);
      return image;
    }
};