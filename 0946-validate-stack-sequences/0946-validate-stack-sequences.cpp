class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
      stack<int> st;
      int n = pu.size(), j = 0;
      for(int i = 0; i < n; i++){
        st.push(pu[i]);
        while(!st.empty() && st.top() == po[j]){
          st.pop();
          j++;
        } 
      }
      return st.empty();
    }
  
};