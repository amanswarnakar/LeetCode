class Solution {
public:
    bool detectCapitalUse(string word) {
      int caps = 0;
      for(auto &s: word){
        if(s - 'A' >= 0 and s - 'A' <= 26) caps++;
      }
      if(caps == 1) return isupper(word[0]);
      return caps == 0 or caps == word.size();
    }
};