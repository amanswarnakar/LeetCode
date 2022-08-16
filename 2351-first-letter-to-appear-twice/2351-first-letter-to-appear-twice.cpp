class Solution {
public:
    char repeatedCharacter(string s) {
      unordered_map<char, int> ump;
      for(int i = 0; i < s.size(); i++){
        ump[s[i]]++;
        if(ump[s[i]] == 2) return s[i];
      }
      return 'a';
    }
};