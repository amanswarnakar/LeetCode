class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
      int n = v.size();
      for(int i = 0; i < n; i++){
        int diff = v[i] - (i + 1);
        if(diff >= k) return i + k;
      }
      return n + k;
    }
};