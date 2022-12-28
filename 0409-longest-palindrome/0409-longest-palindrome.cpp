class Solution {
public:
    int longestPalindrome(string s) {
      vector<int> freq(58, 0);
      for(auto &ch: s){
        freq[ch - 'A']++;
      }
      int cnt = 0;
      for(auto &i: freq){
        if(i % 2) cnt++;
      }
      if(cnt) return accumulate(freq.begin(), freq.end(), 0) - cnt + 1;
      return accumulate(freq.begin(), freq.end(), 0);
    }
};