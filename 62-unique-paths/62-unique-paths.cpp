class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> vec(m, vector<int>(n, 1));
      for(int i = m-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
          vec[i][j] = vec[i+1][j] + vec[i][j+1]; 
        }
      }
      return vec[0][0];
    }
};