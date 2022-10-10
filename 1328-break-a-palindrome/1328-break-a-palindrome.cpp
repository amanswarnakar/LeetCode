class Solution {
public:
    string breakPalindrome(string p) {
      if(p.size() == 1) return "";
      for(int i = 0; i < p.size(); i++){
        if(p[i] != 'a' and i != p.size() / 2){
          p[i] = 'a'; break;
        } else if(p[i] == 'a' and i == p.size() - 1){
          p[i] = 'b';
        }
      }  
      return p;
    }
};