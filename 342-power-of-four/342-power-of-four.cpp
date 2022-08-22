class Solution {
public:
    bool isPowerOfFour(int n) {
      if(n < 0) return false;
      while(n > 0){
        if(n == 1)
          return true;
        else {
          if(n / 4.0 != n / 4)
            return false;
          else n /= 4;
        }
      }
      return false;
    }
};