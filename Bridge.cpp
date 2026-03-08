class Solution {
  public:
    int timer=0;
    void solve(vector<vector<int>> &Adj,vector<bool> &visited,vector<int> &low,vector<int> &start,vector<vector<int>> &ans, int node,int parent){
        visited[node]=true;
        low[node]=start[node]=timer;
        timer++;
        for(auto it:Adj[node]){
            if(parent==it) continue;
            if(!visited[it]){
                solve(Adj,visited,low,start,ans,it,node);
                
                low[node]=min(low[node],low[it]);
                if(start[node]<low[it]){
                    ans.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d){
        vector<vector<int>> Adj(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        vector<bool> visited(V,false);
        vector<int> low(V),start(V);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++){
            solve(Adj,visited,low,start,ans,i,-1);
        }
        for(auto it:ans){
            if((it[0]==c && it[1]==d) || (it[0]==d && it[1]==c)) return true;
        }
        return false;
    }
};
