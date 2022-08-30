class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      // int n = matrix.size();
      // vector<vector<int>> vec(n, vector<int> (n, 0));
      // for(int i = 0; i < n; i++){
      //   for(int j = 0; j < n; j++){
      //     vec[j][n-1-i] = matrix[i][j];
      //   }
      // }
      // for(int i = 0; i < n; i++){
      //   for(int j = 0; j < n; j++){
      //     matrix[i][j] = vec[i][j];
      //   }
      // }
      
      
      // OPTIMIZED SOLUTION
      
      int n = matrix.size();
      for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
          swap(matrix[i][j], matrix[j][i]);
        }
      }
      for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
      }
    }
};