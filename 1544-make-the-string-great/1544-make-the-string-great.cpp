class Solution {
public:
    string makeGood(string s) {
      stack<char> st;
      for(int i = 0; i < s.size(); i++){
        if(st.size() and abs(st.top() - s[i]) == 32) st.pop();
        else st.push(s[i]);
      }
      string ans = "";
      while(st.size()){
        char t = st.top();
        ans = t + ans;
        st.pop();
      }
      return ans;
    }
};