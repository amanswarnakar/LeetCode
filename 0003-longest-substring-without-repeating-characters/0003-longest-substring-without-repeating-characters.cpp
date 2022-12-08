class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> um;
      int n = s.size(), l = 0, r = 0, ans = 0;
      while(r < n){
        um[s[r]]++;
        while(um[s[r]] > 1){
          um[s[l]]--;
          l++;
        }
        r++;
        ans = max(ans, r - l);
      }
      return ans;
    }
};