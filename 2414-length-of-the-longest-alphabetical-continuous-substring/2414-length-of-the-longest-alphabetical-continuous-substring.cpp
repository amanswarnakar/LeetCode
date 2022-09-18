class Solution {
public:
    int longestContinuousSubstring(string s) {
      int n = s.size();
      int ans = 1, temp = 1;
      for(int i = 0; i < n - 1; i++){
        if(s[i+1] == s[i] + 1)
          temp++;
        else temp = 1;
        ans = max(ans, temp);
      }
      return ans;
    }
};