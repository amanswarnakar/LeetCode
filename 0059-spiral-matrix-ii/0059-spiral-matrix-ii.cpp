class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> ans(n, vector<int>(n, 0));
      int sr = 0, sc = 0, er = n - 1, ec = n - 1, total = n * n, cnt = 1;
      while(cnt <= total){
        for(int i = sc; i <= ec and cnt <= total; i++){
          ans[sr][i] = cnt++;
        }
        sr++;
        for(int i = sr; i <= er and cnt <= total; i++){
          ans[i][ec] = cnt++;
        }
        ec--;
        for(int i = ec; i >= sc and cnt <= total; i--){
          ans[er][i] = cnt++;
        }
        er--;
        for(int i = er; i >= sr and cnt <= total; i--){
          ans[i][sc] = cnt++;
        }
        sc++;
      }
      return ans;
    }
};