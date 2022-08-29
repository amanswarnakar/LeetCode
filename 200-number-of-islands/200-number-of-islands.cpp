class Solution {
public:
    void markCurrentIsland(vector<vector<char>> &mat, int x, int y, int r, int c){
      if(x >= r || x < 0 || y >= c || y < 0 || mat[x][y] != '1')
        return;
      mat[x][y] = '2';
      markCurrentIsland(mat, x+1, y, r, c);
      markCurrentIsland(mat, x-1, y, r, c);
      markCurrentIsland(mat, x, y+1, r, c);
      markCurrentIsland(mat, x, y-1, r, c);
    }
    int numIslands(vector<vector<char>>& grid) {
      int r = grid.size();
      if(r == 0) return 0;
      int c = grid[0].size();
      int ans = 0;
      for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
          if(grid[i][j] == '1'){
            markCurrentIsland(grid, i, j, r, c);
            ans++;
          }
        }
      }
      return ans;
    }
};