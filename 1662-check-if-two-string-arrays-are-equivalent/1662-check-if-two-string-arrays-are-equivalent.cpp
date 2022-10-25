class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {
      string p = "", q = "";
      for(string s : a){
        p += s;
      }
      for(string s : b){
        q += s;
      }
      return p == q;
    }
};