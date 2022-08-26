class Solution {
public:
    bool isPowerOfThree(int n) {
      if(n < 0) return false;
      while(n > 0){
        if(n == 1)
          return true;
        else {
          if(n / 3.0 != n / 3)
            return false;
          else n /= 3;
        }
      }
      return false;
    }
};