class Solution {
public:
    void dfs(vector<vector<int>> &v, int r, int c, int col, int pc){
      if(r < 0 || r >= v.size() || c < 0 || c >= v[0].size()) return;
      if(v[r][c] == pc){
        v[r][c] = col;
        dfs(v, r+1, c, col, pc);
        dfs(v, r-1, c, col, pc);
        dfs(v, r, c+1, col, pc);
        dfs(v, r, c-1, col, pc);
      }
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      if(image[sr][sc] != color)
        dfs(image, sr, sc, color, image[sr][sc]);
      return image;
    }
};