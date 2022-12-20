class Solution {
public:
    void dfs(vector<bool>&vis,int node,vector<vector<int>> &rooms){
        if(vis[node]==true){
            return;
        }
        vis[node]=true;
        for(int i=0;i<rooms[node].size();i++){
            dfs(vis,rooms[node][i],rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n+1,false);
        vector<int> node = rooms[0];
        vis[0]=true;
        for(int i=0;i<node.size();i++){
            dfs(vis,node[i],rooms);
        }
        // for(int i=0;i<vis.size();i++){
        //     cout << vis[i] << ' ';
        // }
        // cout << endl;
        for(int i=0;i<vis.size()-1;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};