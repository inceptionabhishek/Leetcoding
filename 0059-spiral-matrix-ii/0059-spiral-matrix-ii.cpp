class Solution {
public:
    void print(vector<vector<int>> ans){
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        int curr = 1;
        int rowsize = n;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int startx = 0;
        int starty = 0;
        int need = n/2;
        while(need != 0){
            cout << startx << ' ' << starty << endl;
            //print(ans);
            // seg1 
            int curr1 = rowsize;
            while(curr1 != 0){
                ans[startx][starty] = curr;
                curr++;
                curr1--;
                starty++;
            }   
            starty--;
            startx++;
            //print(ans);
            // seg2            
            curr1 = rowsize-1;
            while(curr1 != 0){
                ans[startx][starty] = curr;
                curr++;
                curr1--;
                startx++;
            } 
            starty--;
            startx--;
            //print(ans);
            // seg3            
            curr1 = rowsize-1;
            while(curr1 != 0){
                ans[startx][starty] = curr;
                curr++;
                curr1--;
                starty--;
            } 
            starty++;
            startx--;
            //print(ans);
            // seg4          
            curr1 = rowsize-2;
            while(curr1 != 0){
                ans[startx][starty] = curr;
                curr++;
                curr1--;
                startx--;
            } 
            need--;
            startx++;
            starty++;
            rowsize-=2;
        }
        if(n%2){
            ans[n/2][n/2]=n*n;
        }
        return ans;
    }
};