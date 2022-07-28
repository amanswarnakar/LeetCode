class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map<char, int> mp;
      int n = s.length(), m = t.length();
      for(int i = 0; i < n; i++){
        mp[s[i]]++;
      }
      for(int i = 0; i < m; i++){
        if(mp.find(t[i]) != mp.end()){
          mp[t[i]]--;
        } else return false;
      }
      for(auto p : mp){
        if(p.second != 0){
          return false;
        }
      }
      return true;
    }
};