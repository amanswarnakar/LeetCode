class Solution {
public:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; 
    bool dfs(vector<vector<char>> &v, string word, int r, int c, int step = 0){
      if(!word.size()) return true;
      if(min(r, c) < 0 or r >= v.size() or c >= v[0].size()) return false;
      if(v[r][c] != word[0]) return false;
      char ch = v[r][c];
      v[r][c] = '*';
      word = word.substr(1);
      bool up = dfs(v, word, r, c - 1, step+1);
      bool down = dfs(v, word, r, c + 1, step+1);
      bool right = dfs(v, word, r + 1, c, step+1);
      bool left = dfs(v, word, r - 1, c, step+1);
      v[r][c] = ch;
      return up or down or left or right;
    }
    bool exist(vector<vector<char>>& v, string word) {
      int m = v.size(), n = v[0].size(), w = word.size();
      queue<pair<int, int>> q;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(v[i][j] == word[0])
            if(dfs(v, word, i, j)) return true;
        }
      }
      return false;
    }
};