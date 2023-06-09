class Solution {
public:
    bool valid(int n,int m,int i,int j){
        if(i>=n || i<0 || j>=m || j<0){
            return false;
        }
        return true;
    }
    int dfs(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp,int n,int m){
        if(dp[i][j]>0){
            return dp[i][j];
        }
        int ans=1;
        if(valid(n,m,i-1,j) && matrix[i][j] < matrix[i-1][j]){
            ans = max(ans,1+dfs(i-1,j,matrix,dp,n,m));
        }
        if(valid(n,m,i,j-1) && matrix[i][j] < matrix[i][j-1]){
            ans = max(ans,1+dfs(i,j-1,matrix,dp,n,m));
        }
        if(valid(n,m,i,j+1) && matrix[i][j] < matrix[i][j+1]){
            ans = max(ans,1+dfs(i,j+1,matrix,dp,n,m));
        }
        if(valid(n,m,i+1,j) && matrix[i][j] < matrix[i+1][j]){
            ans = max(ans,1+dfs(i+1,j,matrix,dp,n,m));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(i,j,matrix,dp,n,m));
            }
        }
        return ans;
    }
};