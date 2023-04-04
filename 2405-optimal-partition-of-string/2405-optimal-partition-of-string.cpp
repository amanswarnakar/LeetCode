class Solution {
public:
    int partitionString(string s) {
      int n = s.size(), ans = 1;
      unordered_map<char, int> um;
      for(int i = 0; i < n; i++){
        if(um[s[i]] == 1) {
          ans++; um.clear();
        }
        um[s[i]]++;
      }
      return ans;
    }
};