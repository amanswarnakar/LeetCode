class Solution {
public:
    int countDigits(int num) {
      unordered_map<int, int> um;
      int temp = num;
      while(temp){
        int ld = temp % 10;
        temp /= 10;
        um[ld]++;
      }
      int ans = 0;
      for(auto &[f, s]: um){
        if(num % f == 0) ans += s;
      }
      return ans;
    }
};