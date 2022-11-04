class Solution {
public:
    bool isVowel(char ch){
      return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U';
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