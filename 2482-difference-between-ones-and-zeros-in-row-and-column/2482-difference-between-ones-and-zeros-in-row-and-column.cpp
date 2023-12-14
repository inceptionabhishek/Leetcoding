#define pb push_back
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int>row1,row0,col0,col1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<m;j++){
                s+=grid[i][j];
            }
            row1.pb(s);
            row0.pb(m-s);
        }
        for(int i=0;i<m;i++){
            int s=0;
            for(int j=0;j<n;j++){
                s+=grid[j][i];
            }
            col1.pb(s);
            col0.pb(n-s);
        }
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=row1[i]+col1[j]-row0[i]-col0[j];
            }
        }
        return ans;
    }
};