class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size();
      for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n - 1; j++){
          if(v[i][j] != v[i + 1][j + 1])
            return false;
        }
      }
      return true;
    }
};