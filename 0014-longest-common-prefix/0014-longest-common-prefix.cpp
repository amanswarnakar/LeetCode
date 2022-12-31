class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
      string ans = "";
      int minLen = INT_MAX, i = 0, j = 0;
      for(auto &s: v)
        minLen = min(minLen, int(s.size()));
        // if(minLen > s.size()) minLen = s.size();
      while(i < minLen){
        char curr = v[0][i];
        for(auto &s: v){
          if(s[i] != curr)
            return ans;
        }
        ans += curr;
        i++;
      }
      return ans;
    };
};