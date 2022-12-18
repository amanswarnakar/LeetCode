class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t ans = 0;
      for(int i = 0; i < 32; i++){
        ans <<= 1;
        ans += n & 1;
        n >>= 1;
      }
      return ans;
    }
};

/*
    string helper(uint32_t n){
      string s = "";
      while(n){
        s += '0' + n % 2;
        n /= 2;
      }
      return s;
    }
    uint32_t reverseBits(uint32_t n) {
      uint32_t ans = 0;
      string s = helper(n);
      reverse(s.begin(), s.end());
      int cnt = 0;
      for(int i = s.size() - 1; i >= 0; i--){
        ans = ans * 2 + (s[i] == '1');
        cnt++;
      }
      while(cnt++ < 32) ans *= 2;
      return ans;
    }
*/