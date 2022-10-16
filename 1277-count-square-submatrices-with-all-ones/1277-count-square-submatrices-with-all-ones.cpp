class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int tot=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1 && j>=1 && i>=1){
                    matrix[i][j]=min({matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1]})+1;
                }
                tot += matrix[i][j];   
            }
        }
        return tot;
    }
};