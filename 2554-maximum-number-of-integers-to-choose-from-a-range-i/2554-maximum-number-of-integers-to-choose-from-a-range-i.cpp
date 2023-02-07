class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
      vector<int> v;
      set<int> st(banned.begin(), banned.end());
      for(int i = 1; i <= n; i++){
        if(st.find(i) == st.end())
          v.emplace_back(i);
      }
      int i = 0, ans = 0, sum = 0;
      while(i < v.size() and sum + v[i] <= maxSum){
        sum += v[i++];
        ans++;
      }
      return ans;
    }
};