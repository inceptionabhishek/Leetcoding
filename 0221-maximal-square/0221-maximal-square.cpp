class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxy=0;
        vector <vector <int>> v(matrix.size(),vector <int> (matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    v[i][j]=1;
                }else{
                    v[i][j]=0;                
                }
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(i>=1 && j>=1 && v[i][j]==1){
                    v[i][j]=1+min({v[i][j-1],v[i-1][j],v[i-1][j-1]});
                }
                maxy=max(maxy,v[i][j]);
            }
        }
        return maxy*maxy;
    }
};