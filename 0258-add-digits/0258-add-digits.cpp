class Solution {
public:
    int sumOfDigits(int n){
      int res = 0;
      while(n){
        res += n % 10;
        n /= 10;
      }
      return res;
    }
    int addDigits(int n) {
      int sum = 0;
      while(true){
        if(n < 10) return n;
        n = sumOfDigits(n);
      }
      return 0;
    }
};