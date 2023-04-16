class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
      vector<int> ans(2, 0);
      for(int i = mat.size() - 1; i >= 0; i--){
        int temp = 0;
        for(int j = 0; j < mat[0].size(); j++){
          if(mat[i][j] == 1) temp++;
        }
        if(temp >= ans[1]){
          ans[0] = i;
          ans[1] = temp;
        }
      }
      return ans;
    }
};