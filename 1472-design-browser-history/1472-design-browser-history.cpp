class BrowserHistory {
public:
    int curr, r;
    vector<string> ds;
    BrowserHistory(string homepage) {
      ds.resize(1);
      ds[0] = homepage;
      curr = 0; r = ds.size();
      
      // cout<<curr<<" "<<r<<endl;
      // for(auto &i: ds)  cout<<i<<" ";
      // cout<<endl;
    }
    
    void visit(string url) {
      curr++;
      if(curr == ds.size()){
        ds.emplace_back(url);
        r = ds.size();
      } 
      else {
        r = curr + 1;
        ds.resize(curr + 1);
        // ds.emplace_back(url);
        ds[curr] = url;
      }
            
      // cout<<curr<<" "<<r<<endl;
      // for(auto &i: ds)  cout<<i<<" ";
      // cout<<endl;
    }
    
    string back(int steps) {
      curr = max(0, curr - steps);
      
      // cout<<curr<<" "<<r<<endl;
      // for(auto &i: ds)  cout<<i<<" ";
      // cout<<endl<<ds[curr]<<endl;
      
      return ds[curr];
    }
    
    string forward(int steps) {
      curr = min(r - 1, curr + steps);
      
      // cout<<curr<<" "<<r<<endl;
      // for(auto &i: ds)  cout<<i<<" ";
      // cout<<endl<<ds[curr]<<endl;

      return ds[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */