class Solution {
public:
    bool isSubsequence(string s, string t) {
      int l = 0, r = 0;
      if(t.size() < s.size()) return false;
      while(l < s.size() and r < t.size()){
        if(s[l] == t[r]) l++, r++;
        else r++;
      }
      return l == s.size();
    }
};