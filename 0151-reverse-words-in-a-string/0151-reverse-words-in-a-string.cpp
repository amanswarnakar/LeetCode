class Solution {
public:
  string reverseWords(string s) {
    stack<string> st;
    for(int i = 0; i < s.size(); i++){
      string temp = "";
      while(i < s.size() and s[i] != ' ') temp += s[i++];
      if(temp != "") st.push(temp);
    }
    string ans = "";
    bool flag = false;
    while(!st.empty()){
      // cout<<st.top()<<"~";
      if(flag) ans += " ";
      flag = true;
      ans += st.top();
      st.pop();
    }
    // cout<<endl;
    return ans;
  }
};