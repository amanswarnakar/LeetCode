class Solution {
public:
    string mergeAlternately(string p, string q) {
      string ans = "";
      int m = p.size(), n = q.size(), i = 0, j = 0;
      while(i < m and j < n){
        ans += p[i++];
        ans += q[j++];
      }
      while(i < m) ans += p[i++];
      while(j < n) ans += q[j++];
      return ans;
    }
};