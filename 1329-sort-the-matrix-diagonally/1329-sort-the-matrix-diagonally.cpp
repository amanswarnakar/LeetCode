class Solution {
public:
    void sortDiagonally(vector<vector<int>> &mat, int r, int c){
      int m = mat.size(), n = mat[0].size();
      vector<int> arr(101, 0);
      int i = r, j = c;
      while(i < m and j < n){
        arr[mat[i][j]-1]++;
        i++; j++;
      }
      for(int k = 0; k < arr.size(); k++){
        while(arr[k] > 0){
          mat[r++][c++] = k + 1;
          arr[k]--;
        }
      }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      // Using map of priority queue
      
      // int m = mat.size(), n = mat[0].size();
      // map<int, priority_queue<int, vector<int>, greater<int>>> mp;
      // for(int i = 0; i < m; i++){
      //   for(int j = 0; j < n; j++){
      //     mp[i-j].push(mat[i][j]);
      //   }
      // }
      // for(int i = 0; i < m; i++){
      //   for(int j = 0; j < n; j++){
      //     mat[i][j] = mp[i-j].top();
      //     mp[i-j].pop();
      //   }
      // }
      // return mat;
      
      
      // Using count sort
      int m = mat.size(), n = mat[0].size();
      for(int i = 0; i < m; i++){
        sortDiagonally(mat, i, 0);
      }
      for(int i = 1; i < n; i++){
        sortDiagonally(mat, 0, i);
      }
      return mat;
    }
};