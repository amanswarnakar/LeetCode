class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      int n = tokens.size();
      sort(tokens.begin(), tokens.end());
      int l = 0, r = n-1;
      int score = 0, ans = 0;
      if(n == 0 or tokens[0] > power) return 0;
      while(l <= r){
        if(power >= tokens[l]) { score++; power -= tokens[l]; l++;}
        else {
          if(score > 0) { score--; power += tokens[r]; r--;}
        }
        ans = max(score, ans);
      }
      return ans;
    }
};