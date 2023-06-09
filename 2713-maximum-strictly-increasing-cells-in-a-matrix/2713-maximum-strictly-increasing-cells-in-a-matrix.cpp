class Solution {
public:
int maxIncreasingCells(vector<vector<int>>& mat) {
        int ans= INT_MIN;
        int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));
        vector<int>row(n,0);
        vector<int>col(m,0);
        unordered_map<int,vector<pair<int,int>>>ump;
        set<int,greater<int>>s;
        set<int, greater<int> >::iterator itr;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int val= mat[i][j];
                ump[val].push_back({i,j});
                s.insert(mat[i][j]);
            }
        }
        for(auto x:s){
            int val=x;
            for(auto ele:ump[val]){
                int r= ele.first;
                int c= ele.second;
                temp[r][c]= max(row[r],col[c])+1;    
            }
            for(auto ele:ump[val]){
                int r= ele.first;
                int c= ele.second;
                row[r]= max(row[r],temp[r][c]);
                col[c]= max(col[c],temp[r][c]);
                
            }
        }
        for(int i=0;i<n; i++){
            ans= max(ans,row[i]);
            
        }
        for(int j=0; j<m; j++){
            ans= max(ans,col[j]);
        }
      
        return ans;
    }
};