class Solution {
public:
    string breakPalindrome(string p) {
      int n = p.size();
      if(n == 1) return "";
      for(int i = 0; i < n; i++){
        if(p[i] != 'a' and i != n / 2){
          p[i] = 'a'; break;
        } else if(p[i] == 'a' and i == n - 1){
          p[i] = 'b';
        }
      }  
      return p;
    }
};