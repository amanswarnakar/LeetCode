class Solution {
public:
    string getHint(string s, string g) {
      int n = s.size(), x = 0, y = 0;
      vector<int> vs(10, 0), vg(10, 0);
      for(int i = 0; i < n; i++){
        if(s[i] == g[i]) x++;
        else {
          vs[g[i] - '0']++;
          vg[s[i] - '0']++;
        }
      }
      for(int i = 0; i < 10; i++)
        y += min(vg[i], vs[i]);
      string ans = to_string(x) + "A" + to_string(y) + "B";
      return ans;
    }
};