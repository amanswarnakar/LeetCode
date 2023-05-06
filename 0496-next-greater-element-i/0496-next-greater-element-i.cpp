class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
      stack<int> st;
      vector<int> ans;
      unordered_map<int, int> um;
      for(auto &i: v2){
        while(st.size() and st.top() < i){
          um[st.top()] = i;
          st.pop();
        }
        st.push(i);
      }
      for(int &i: v1){
        ans.emplace_back(um.count(i) ? um[i] : -1);
      }
      return ans;
    }
};