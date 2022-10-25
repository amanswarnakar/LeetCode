class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {
      string p = "";
      for(string s : a){
        p += s;
      }
      string q = "";
      for(string s : b){
        q += s;
      }
      return p == q;
    }
};