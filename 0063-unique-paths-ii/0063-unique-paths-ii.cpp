class Solution {
public:
    int dp[104][104];
    int ans(vector <vector <int>> &obstacleGrid,int i,int j){
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=ans(obstacleGrid,i+1,j)+ans(obstacleGrid,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        return ans(obstacleGrid,0,0);
    }
};