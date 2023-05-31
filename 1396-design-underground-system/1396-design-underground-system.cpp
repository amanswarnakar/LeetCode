class UndergroundSystem {
public:
  unordered_map<int, pair<string, int>> checkinMap; // Uid -> {stationName, time}
  unordered_map<string, pair<double, int>> routeMap; // stationName -> {totalTime, cnt}
  UndergroundSystem() {}

  void checkIn(int id, string s, int t) {
    checkinMap[id] = {s, t};
  }

  void checkOut(int id, string s, int t) {
    auto checkin = checkinMap[id];
    checkinMap.erase(id);
    
    string route = checkin.first + "#" + s;
    routeMap[route].first += t - checkin.second;
    routeMap[route].second++;
  } 

  double getAverageTime(string ss, string es) {
    string route = ss + "#" + es;
    return routeMap[route].first / routeMap[route].second;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */