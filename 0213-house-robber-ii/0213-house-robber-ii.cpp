class Solution {
public:
    int helper(vector<int> &v){
      int prev = v[0], prev2 = 0, n = v.size();
      for(int i = 1; i < n; i++){
        int pick = v[i];
        if(i > 1) pick += prev2;
        int notPick = 0 + prev;
        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
      }
      return prev;
    }
    int rob(vector<int>& v) {
      int n = v.size();
      if(n == 1) return v[0];
      vector<int> temp1, temp2;
      for(int i = 0; i < n; i++){
        if(i != 0) temp1.emplace_back(v[i]);
        if(i != n - 1) temp2.emplace_back(v[i]);
      }
      return max(helper(temp1), helper(temp2));
    }
};