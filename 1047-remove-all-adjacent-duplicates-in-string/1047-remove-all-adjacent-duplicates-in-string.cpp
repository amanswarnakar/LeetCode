class Solution {
public:
    string removeDuplicates(string s) {
      stack<char> st;
      for(int i = 0; i < s.size(); i++){
        if(st.size() and st.top() == s[i]) st.pop();
        else st.push(s[i]);
      }
      string ans = "";
      while(!st.empty()){
        char t = st.top();
        ans = t + ans;
        st.pop();
      }
      return ans;
    }
};