class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
      int ans = INT_MIN, cnt0 = 0, cnt1 = 0, n = s.size();
      for(int i = 0; i < n; i++){
        int j = i, k;
        while(j < n){
          if(s[j] == '0') cnt0++;
          else break;
          j++;
        }
        while(j < n){
          if(s[j] == '1') cnt1++;
          else break;
          j++;
          if(cnt1 == cnt0) ans = max(ans, j - i);
        }
        cnt1 = 0, cnt0 = 0;
      }
      return ans == INT_MIN ? 0 : ans;
    }
};