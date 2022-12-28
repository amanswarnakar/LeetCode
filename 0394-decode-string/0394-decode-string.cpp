class Solution {
public:
    string decodeString(string s) {
      stack<string> st; 
      stack<int> nt;
      string ans = "";
      int num = 0;
      for(auto &ch: s){
        if(isdigit(ch)){
          num = num * 10 + (ch - '0');
        } else if(isalpha(ch)){
          ans += ch;
        } else if(ch == '['){
          st.push(ans);
          nt.push(num);
          num = 0; ans = "";
        } else if(ch == ']'){
          string temp = ans;
          for(int i = 0; i < nt.top() - 1; i++){
            ans += temp;
          } 
          ans = st.top() + ans;
          st.pop(); nt.pop();
        }
      }
      return ans;
    }
};