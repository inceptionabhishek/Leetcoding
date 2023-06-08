class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            int l=0,r=grid[i].size()-1;
            reverse(grid[i].begin(),grid[i].end());
            int lastpos=-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(grid[i][mid] >= 0){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                    lastpos=mid;
                }
            }
            cout << lastpos << endl;
            if(lastpos!=-1){
                cnt += (lastpos+1);
            }
        }
        return cnt;
    }
};