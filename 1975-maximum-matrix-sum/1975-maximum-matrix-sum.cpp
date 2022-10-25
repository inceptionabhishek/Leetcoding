class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long cnt=0;
        long long sum=0;
        long long mini=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]<0){
                    cnt++;
                }
                mini=min(mini,1LL*abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }

        if(cnt%2==0){
            return sum;
        }
        return sum-2*mini;
    }
};