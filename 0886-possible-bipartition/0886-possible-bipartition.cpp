class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        vector<int>color(n+1,0);
        
        
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                color[i]=1;
                q.push(i);
                while(!q.empty()){
                    int fi=q.front();
                    vis[fi]=1;
                    q.pop();
                    for(auto j:adj[fi]){
                        if(color[j]==0){
                            color[j]=3-color[fi];
                            q.push(j);
                        }else if(color[j]==color[fi]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};