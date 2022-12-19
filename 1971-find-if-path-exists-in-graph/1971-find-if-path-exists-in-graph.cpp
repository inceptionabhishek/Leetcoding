class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool found=0;
        vector<bool>vis(n+1,false);
        auto dfs = [&](int node,auto&& dfs){
            if(found){
                return;
            }
            if(vis[node]==true){
                return;
            }
            vis[node]=true;
            if(node==destination){
                found=1;
                return;
            }
            for(auto j:adj[node]){
                dfs(j,dfs);
            }
        };
        dfs(source,dfs);
        return found==1;
    }
};