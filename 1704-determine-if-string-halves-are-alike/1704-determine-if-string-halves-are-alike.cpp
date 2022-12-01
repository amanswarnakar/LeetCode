class Solution {
public:
    bool helper(char c){
      return (c == 'a') or (c == 'e') or (c == 'i') or (c == 'o') or (c == 'u') or (c == 'A') or (c == 'E') or (c == 'I') or (c == 'O') or (c == 'U'); 
    }
    bool halvesAreAlike(string s) {
      int n = s.size(), ans = 0;
      for(int i = 0; i < n / 2; i++){
        if(helper(s[i])) ans++;
        if(helper(s[i + n / 2])) ans--;
      }
      return !ans;
    }
};