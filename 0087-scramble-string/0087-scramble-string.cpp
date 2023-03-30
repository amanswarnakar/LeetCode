class Solution {
public:
    unordered_map<string, bool> um;
    bool solve(string x, string y, int n){
      if(x == y)  return um[x + "#" + y] = true;
      else if(x.size() == 1) return false;
      if(um.count(x + "#" + y)) return um[x + "#" + y];
      for(int i = 1; i < n; i++){
        bool cond1 = solve(x.substr(0, i), y.substr(n - i), i) 
          and solve(x.substr(i, n - i), y.substr(0, n - i), n - i);
        bool cond2 = solve(x.substr(0, i), y.substr(0, i), i) and
          solve(x.substr(i, n - i), y.substr(i, n - i), n - i);
        if(cond1 or cond2) return um[x + "#" + y] = true;
      }
      return um[x + "#" + y] = false;
    }
      
    bool isScramble(string s1, string s2) {
      int n = s1.size();
      return solve(s1, s2, n);
    }
  
  /*
    bool isScramble(string s1, string s2) {
      // TLE
      
      if(s1 == s2) return true;
      int n = s1.size();
      vector<int> count(26, 0);
      for(auto &i: s1) count[i - 'a']++;
      for(auto &i: s2) count[i - 'a']--;
      for(auto &i: count) if(i != 0) return false;
      for(int i = 1; i < n; i++){
        if(isScramble(s1.substr(0, i), s2.substr(0, i)) and isScramble(s1.substr(i), s2.substr(i))) return true;
        if(isScramble(s1.substr(0, i), s2.substr(n - i)) and isScramble(s1.substr(i), s2.substr(0, n - i))) return true;
      }
      return false;
    }
  */
};