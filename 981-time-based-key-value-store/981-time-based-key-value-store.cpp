class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> um;
    // unordered_map<string, map<int, string>> mp;
    TimeMap() {
      
    }
    
    void set(string key, string value, int timestamp) {
      um[key].push_back({timestamp, value});  
      // mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
      if(um.find(key) == um.end())  return "";
      if(timestamp < um[key][0].first)  return "";
      
      int l = 0, r = um[key].size();
      while(l < r){
        int mid = l + (r - l) / 2;
        if(um[key][mid].first == timestamp) return um[key][mid].second;
        else if(um[key][mid].first > timestamp) r = mid;
        else l = mid + 1;
      }
      
      return um[key][r - 1].second;
      
      
      // string ans, temp;
      // for(int i = 0; i < um[key].size(); i++){
      //   if(um[key][i].second <= timestamp)
      //     temp = um[key][i].first;
      //   ans = temp;
      // }
      // return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */