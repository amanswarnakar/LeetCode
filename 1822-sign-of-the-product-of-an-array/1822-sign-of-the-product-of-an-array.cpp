class Solution {
public:
    int arraySign(vector<int>& v) {
      int ans = 1;
      for(auto &i: v){
        if(i == 0) return 0;
        else if(i < 0) ans *= -1;
      }
      return ans;
    }
};