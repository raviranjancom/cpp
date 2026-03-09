// User function Template for C++

class Solution {
  public:
    int timer=0;
    void dfs(vector<int> adj[],vector<int>& start,vector<int>& low,vector<bool> &visited,
    set<int> &st,int node,int parent){
        visited[node]=true;
        start[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto &it:adj[node]){
            if(parent==it) continue;
            if(!visited[it]){
                child++;
                dfs(adj,start,low,visited,st,it,node);
                low[node]=min(low[node],low[it]);
                if(low[it]>=start[node] && parent!=-1){
                    st.insert(node);
                }
            }
            else{
                low[node]=min(low[node],start[it]);
            }
        }
        
        if(child>1 && parent==-1) st.insert(node);
    }
    vector<int> articulationPoints(int V, vector<int> adj[]){
        vector<int> start(V),low(V);
        set<int> st;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs(adj,start,low,visited,st,i,-1);
        }
        vector<int> ans(st.begin(),st.end());
        if(st.size()==0) return {-1};
        return ans;
    }
};
