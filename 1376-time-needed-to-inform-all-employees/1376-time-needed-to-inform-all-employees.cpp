class Solution {
public:
    vector<int>adj[100001];
    bool vis[100001];
    int ans=0;
    int dfs(int node,vector<int>&informTime){
        vis[node]=true;
        int t=0;
        for(auto j:adj[node]){
            if(!vis[j]){
                t=max(t,dfs(j,informTime));
            }
        }
        return t+informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int root;
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1){
                root=i;
                continue;
            }
            adj[manager[i]].push_back(i);
            adj[i].push_back(manager[i]);
        }
        
        return dfs(headID,informTime);;
    }
};