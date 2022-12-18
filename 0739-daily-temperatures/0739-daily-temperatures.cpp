class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
      int n = v.size();
      stack<int> st;
      vector<int> ans(n, 0);
      for(int i = 0; i < n; i++){
        while(st.size() and v[st.top()] < v[i]){
          ans[st.top()] = i - st.top();
          st.pop();
        }
        st.push(i);
      }
      return ans;
    }
};