class Solution {
public:
    const int maxn = 101;
    bool vis[101][101];
    bool valid(int i,int j,int n,vector<vector<int>>&grid){
        if(i>=n || i<0 || j>=n || j<0 || grid[i][j]==0 || vis[i][j]==1){
            return false;
        }
        return true;
    }
    void dfs(int i,int j,int color,vector<vector<int>>& grid,int n){
        if(!valid(i,j,n,grid)){
            return;
        }
        vis[i][j]=true;
        grid[i][j]=color;
        dfs(i+1,j,color,grid,n);
        dfs(i,j+1,color,grid,n);
        dfs(i-1,j,color,grid,n);
        dfs(i,j-1,color,grid,n);
    }
    bool valid2(int i,int j,int n,vector<vector<int>>&grid){
        if(i>=n || i<0 || j>=n || j<0 || grid[i][j]==0 || vis[i][j]==1){
            return false;
        }
        return true;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int color = 3;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    dfs(i,j,color,grid,n);
                    color++;
                }
            }
        }
        int ans=INT_MAX;
        vector<pair<int,int>> island1,island2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << grid[i][j] << ' ';
                if(grid[i][j]==3){
                    island1.push_back(make_pair(i,j));
                }else if(grid[i][j]==4){
                    island2.push_back(make_pair(i,j));
                }
            }
            cout << endl;
        }
        for(auto j:island1){
            cout << j.first << ' ' << j.second << endl;
        }
        
        for(auto j:island2){
            cout << j.first << ' ' << j.second << endl;
        }
        for(auto j:island1){
            for(auto k:island2){
                int dist = abs(j.first-k.first)+abs(j.second-k.second)-1;
                ans=min(ans,dist);
            }
        }
        return ans;
    }
};