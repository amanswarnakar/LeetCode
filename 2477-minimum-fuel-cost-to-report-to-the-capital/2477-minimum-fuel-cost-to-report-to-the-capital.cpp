class Solution {
public:
    void countChild(int index, vector<vector<int>> &graph, vector<int> &child) {
        child[index]=1;
        for(auto &x: graph[index]){
            if(child[x]==0){
                countChild(x,graph,child);
                child[index]+=child[x];
            }
        }
        return;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        for(int i = 0; i < n - 1; i++){
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int> child(n, 0), vis(n, 0);
        countChild(0,graph,child);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        long long minFuel = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &x: graph[curr]){
                if(vis[x]==1) continue;
                int cnt = child[x];
                minFuel+=cnt/seats;
                if(cnt%seats) minFuel++;
                q.push(x);
                vis[x]=1;
            }
        }
        return minFuel;
    }
};