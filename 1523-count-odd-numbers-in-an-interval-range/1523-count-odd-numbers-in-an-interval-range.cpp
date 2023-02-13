class Solution {
public:
    int countOdds(int low, int high) {
      int sz = high - low + 1;
      if(sz % 2 == 0) return sz / 2;
      if(low % 2 == 0) return sz / 2;
      return sz / 2 + 1;
    }
};