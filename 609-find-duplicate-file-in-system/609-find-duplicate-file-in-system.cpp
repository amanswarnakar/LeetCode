class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      unordered_map<string, vector<string>> um;
      vector<vector<string>> ans;
      for(auto s : paths){
        int i = 0, j;
        while(s[i] != ' ') i++;
        string dir = s.substr(0, i), file, cont;
        while(i < s.size()){
          j = i + 1;
          while(s[i] != '(') i++;
          file = s.substr(j, i - j);
          j = i + 1;
          while(s[i] != ')') i++;
          cont = s.substr(j, i - j);
          um[cont].push_back(dir + '/' + file);
          // cout<<dir<<" "<<file<<" "<<cont<<endl;
          i++;
        }
      }
      for(auto i : um){
        if(i.second.size() > 1){
          vector<string> temp;
          for(auto j : i.second){
            temp.push_back(j);
            // cout<<i.first<<"~"<<j<<endl;
          }
          ans.push_back(temp);
        }
      }
      return ans;
    }
};