class Solution {
  public:
    vector<vector<int>> Adj;
    void dfs(stack<int> &st,vector<bool> &visited,int node){
        visited[node]=true;
        for(int it:Adj[node]){
            if(visited[it]==false){
                dfs(st,visited,it);
            }
        }
        st.push(node);
    }
    void dfs2(vector<vector<int>> &Adj,vector<bool> &visited,int node){
        visited[node]=true;
        for(int it:Adj[node]){
            if(visited[it]==false){
                dfs2(Adj,visited,it);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges){
        Adj.resize(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            Adj[u].push_back(v);
        }
        stack<int> st;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(st,visited,i);
            }
        }
        vector<vector<int>> Adj2(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            Adj2[v].push_back(u);
        }
        visited.assign(V,false);
        int ans=0;
        while(!st.empty()){
            int t=st.top(); st.pop();
            if(visited[t]==false){
                ans++;
                dfs2(Adj2,visited,t);
            }
        }
        return ans;
    }
};
