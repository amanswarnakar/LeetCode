class Solution {
public:
    bool isVowel(char ch){
      string check = "aeiouAEIOU";
      for(auto &c: check)
        if(ch == c) return true;
      return false;
    }
    string reverseVowels(string s) {
      int l = 0, r = s.size();
      while(l < r){
        if(!isVowel(s[l])) l++;
        if(!isVowel(s[r])) r--;
        if(isVowel(s[l]) and isVowel(s[r])){
          swap(s[l], s[r]);
          l++; r--;
        }
      }
      return s;
    }
};