class Solution {
public:
    int strStr(string s, string f) {
      int m = s.size(), n = f.size();
      for(int i = 0; i <= m - n; i++){
        for(int j = 0; j < n; j++){
          if(s[i + j] != f[j]) break;
          if(j == n - 1) return i;
        }
      }
      return -1;
    }
};