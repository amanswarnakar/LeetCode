class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
      int m = mat.size(), n = mat[0].size();
      vector<int> ans;
      int sr = 0, sc = 0, er = m - 1, ec = n - 1, total = m * n - 1, cnt = 0;
      while(cnt <= total){
        for(int i = sc; i <= ec and cnt <= total; i++){
          ans.emplace_back(mat[sr][i]); cnt++;
        }
        sr++;
        for(int i = sr; i <= er and cnt <= total; i++){
          ans.emplace_back(mat[i][ec]); cnt++;
        }
        ec--;
        for(int i = ec; i >= sc and cnt <= total; i--){
          ans.emplace_back(mat[er][i]); cnt++;
        }
        er--;
        for(int i = er; i >= sr and cnt <= total; i--){
          ans.emplace_back(mat[i][sc]); cnt++;
        }
        sc++;
      }
      return ans;
    }
};