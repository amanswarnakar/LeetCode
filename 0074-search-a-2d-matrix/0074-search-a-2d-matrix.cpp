class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//       BINARY SEARCH APPROACH
      int rows = matrix.size(), cols = matrix[0].size();
      int l = 0, r = rows*cols - 1;
      while(l <= r){
        int mid = l + (r-l)/2;
        if(matrix[mid / cols][mid % cols] == target) return true;
        else if(matrix[mid / cols][mid % cols] < target) l = mid+1;
        else r = mid-1;
      }
      return false; 
      
      
//       EDGE CASE WRONG - matrix = [[1]], target = 2 
      // int row = 0, m = matrix.size(), n = matrix[0].size();
      // if(m == 1 && n == 1 && matrix[0][0] !){
      // }
      // for(int i = 0; i < m; i++){
      //   if(matrix[i][n-1] < target){
      //     row++;
      //   } else if(matrix[i][n-1] == target){
      //     return true;
      //   } else {
      //     break;
      //   }
      // }
      // for(int i = 0; i < n; i++){
      //   if(matrix[row][i] == target){
      //     return true;
      //   }
      // }
      // return false;
      
      // NEXT APPROACH
      // int rows = matrix.size(), cols = matrix[0].size();
      // int row = 0, col = cols-1;
      // while(row < rows and col >= 0){
      //   if(matrix[row][col] == target) return true;
      //   if(matrix[row][col] < target) row++;
      //   else col--;
      // }
      // return false;
    }
};