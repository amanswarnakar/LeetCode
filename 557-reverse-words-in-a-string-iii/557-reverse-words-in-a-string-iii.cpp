class Solution {
public:
      // Two Pointer Approach
    string reverse(string s){
      int l = 0, r = s.size() - 1;
      while(l < r) swap(s[l++], s[r--]);
      return s;
    }
  
    string reverseWords(string s) {
      string ans = "";
      for(int i = 0; i < s.size(); i++){
        string temp = "";
        while(i < s.size() and s[i] != ' ') temp += s[i++];
        ans += reverse(temp);
        if(i != s.size())
          ans += ' ';
        // cout<<temp<<" ~ "<<ans<<"\n";
      }
      return ans;
    }
};