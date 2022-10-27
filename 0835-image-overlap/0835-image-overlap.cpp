class Solution {
public:
    int helper(vector<vector<int>> &a, vector<vector<int>> &b, int r, int c){
      int res = 0, n = a.size();
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(i + r < 0 or i + r >= n or j + c < 0 or j + c >= n)  continue;
          if(a[i][j] + b[i + r][j + c] == 2)
            res++;
        }
      }
      return res;
    }
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
      int n = a.size(), ans = 0;
      for(int i = - n + 1; i < n; i++){
        for(int j = - n + 1; j < n; j++){
          ans = max(ans, helper(a, b, i, j));
        }
      }
      return ans;
    }
  
  
  /*    int shiftAndCount(int i, int j, vector<vector<int>> &a, vector<vector<int>> &b){
      int lcnt = 0, rcnt = 0, cnt = 0;
      int r = 0;
      for (int x = j; x < a.size(); ++x) {
        int c = 0;
        for (int y = i; y < a.size(); ++y) {
          if (a[x][y] == 1 && a[x][y] == b[r][c])
            lcnt++;
          if (a[x][c] == 1 && a[x][c] == b[r][c])
            rcnt++;
          c++;
        }
        r++;
      }
      r = 0;
      for (int x = j; x < a.size(); ++x) {
        int c = i;
        for (int y = 0; y < a.size() - i; ++y) {
          if (a[x][y] == 1 && a[x][y] == b[r][c])
            cnt++;
          c++;
        }
        r++;
      }
      return max(lcnt, max(rcnt, cnt));
    }
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
      int ans = 0, n = a.size();
      for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
          ans = max(ans, shiftAndCount(i, j, a, b));
          ans = max(ans, shiftAndCount(i, j, b, a));
        }
      }
      return ans;
    }  */
};